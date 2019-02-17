#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Part of the PsychoPy library
# Copyright (C) 2018 Jonathan Peirce
# Distributed under the terms of the GNU General Public License (GPL).

"""Provides functions for logging error and other messages to one or more
files and/or the console, using python's own logging module. Some warning
messages and error messages are generated by PsychoPy itself. The user can
generate more using the functions in this module.

There are various levels for logged messages with the following order of
importance: ERROR, WARNING, DATA, EXP, INFO and DEBUG.

When setting the level for a particular log target (e.g. LogFile)
the  user can set the minimum level that is required
for messages to enter the log. For example, setting a level of INFO will
result in INFO, EXP, DATA, WARNING and ERROR messages to be recorded but not
DEBUG messages.

By default, PsychoPy will record messages of WARNING level and above to
the console. The user can silence that by setting it to receive only CRITICAL
messages, (which PsychoPy doesn't use) using the commands::

    from psychopy import logging
    logging.console.setLevel(logging.CRITICAL)

"""

# Much of the code below is based conceptually, if not syntactically, on the
# python logging module but it's simpler (no threading) and maintaining a
# stack of log entries for later writing (don't want files written while
# drawing)

from __future__ import absolute_import, print_function

from builtins import object
from past.builtins import basestring
from os import path
import atexit
import sys
import codecs
import locale
from psychopy import clock
from psychopy.constants import PY3

_packagePath = path.split(__file__)[0]

CRITICAL = 50
FATAL = CRITICAL
ERROR = 40
DEPRECATION = ERROR
WARNING = 30
WARN = WARNING
DATA = 25  # will be a custom level
EXP = 22  # info about the experiment might be less important than data info?
INFO = 20
DEBUG = 10
NOTSET = 0

_levelNames = {
    CRITICAL: 'CRITICAL',
    ERROR: 'ERROR',
    WARNING: 'WARNING',
    DATA: 'DATA',
    EXP: 'EXP',
    INFO: 'INFO',
    DEBUG: 'DEBUG',
    NOTSET: 'NOTSET',
    'CRITICAL': CRITICAL,
    'ERROR': ERROR,
    'DEPRECATION': DEPRECATION,
    'DATA': DATA,
    'EXP': EXP,
    'WARN': WARNING,
    'WARNING': WARNING,
    'INFO': INFO,
    'DEBUG': DEBUG,
    'NOTSET': NOTSET}

_prefEncoding = locale.getpreferredencoding()

def getLevel(level):
    """Return the textual representation of logging level 'level'.

    If the level is one of the predefined levels (CRITICAL, ERROR, WARNING,
    INFO, DEBUG) then you get the corresponding string. If you have
    associated levels with names using addLevelName then the name you have
    associated with 'level' is returned.

    If a numeric value corresponding to one of the defined levels is passed
    in, the corresponding string representation is returned.

    Otherwise, the string "Level %s" % level is returned.
    """
    return _levelNames.get(level, "Level %s" % level)


def addLevel(level, levelName):
    """Associate 'levelName' with 'level'.

    This is used when converting levels to text during message formatting.
    """
    _levelNames[level] = levelName
    _levelNames[levelName] = level


# global defaultClock
defaultClock = clock.monotonicClock


def setDefaultClock(clock):
    """Set the default clock to be used to reference all logging times.
    Must be a :class:`psychopy.core.Clock` object. Beware that if you
    reset the clock during the experiment then the resets will be
    reflected here. That might be useful if you want your logs to be
    reset on each trial, but probably not.
    """
    global defaultClock
    defaultClock = clock


class _LogEntry(object):

    def __init__(self, level, message, t=None, obj=None):
        super(_LogEntry, self).__init__()
        self.t = t
        self.t_ms = t * 1000
        self.level = level
        self.levelname = getLevel(level)
        self.message = message
        self.obj = obj


class LogFile(object):
    """A text stream to receive inputs from the logging system
    """

    def __init__(self, f=None, level=WARNING, filemode='a', logger=None,
                 encoding='utf8'):
        """Create a log file as a target for logged entries of a given level

        :parameters:

            - f:
                this could be a string to a path, that will be created if it
                doesn't exist. Alternatively this could be a file object,
                sys.stdout or any object that supports .write() and .flush()
                methods

            - level:
                The minimum level of importance that a message must have
                to be logged by this target.

            - filemode: 'a', 'w'
                Append or overwrite existing log file

        """
        super(LogFile, self).__init__()
        # work out if this is a filename or a stream to write to
        if f is None:
            self.stream = 'stdout'
        elif hasattr(f, 'write'):
            self.stream = f
        elif isinstance(f, basestring):
            self.stream = codecs.open(f, filemode, encoding)
        self.level = level
        if logger is None:
            logger = root
        # Can not use weak ref to logger, as sometimes this class
        # instance would be gc'ed before _Logger.__del__
        # was complete (running .flush()).
        # This was causing following error when script closed:
        #     Exception AttributeError: "'NoneType' object has no
        #       attribute 'stdout'" in
        #     <bound method _Logger.__del__ of
        #       <psychopy.logging._Logger instance at 0x102e0d878>> ignored
        # So instead free logger ref in __del__ of this class,
        # so we know any log backlog can be flushed before it is gc'ed.
        self.logger = logger

        self.logger.addTarget(self)

    def setLevel(self, level):
        """Set a new minimal level for the log file/stream
        """
        if type(level) is not int:
            raise TypeError("LogFile.setLevel() should be given an int, which"
                            "is usually one of logging.INFO (not logging.info)")
        self.level = level
        self.logger._calcLowestTarget()

    def write(self, txt):
        """Write directly to the log file (without using logging functions).
        Useful to send messages that only this file receives
        """
        # find the current stdout if we're the console logger
        if self.stream == 'stdout':
            if PY3:
                stream = sys.stdout
            else:
                stream = codecs.getwriter(_prefEncoding)(sys.stdout)
        else:
            stream = self.stream
        stream.write(txt)
        try:
            stream.flush()
        except Exception:
            pass


class _Logger(object):
    """Maintains a set of log targets (text streams such as files of stdout)

    self.targets is a list of dicts {'stream':stream, 'level':level}

    """

    def __init__(self, format="%(t).4f \t%(levelname)s \t%(message)s"):
        """The string-formatted elements %(xxxx)f can be used, where
        each xxxx is an attribute of the LogEntry.
        e.g. t, t_ms, level, levelname, message
        """
        super(_Logger, self).__init__()
        self.targets = []
        self.flushed = []
        self.toFlush = []
        self.format = format
        self.lowestTarget = 50

    def __del__(self):
        self.flush()
        # unicode logged to coder output window can cause logger failure, with
        # error message pointing here. this is despite it being ok to log to
        # terminal or Builder output. proper fix: fix coder unicode bug #97
        # (currently closed)

    def addTarget(self, target):
        """Add a target, typically a :class:`~log.LogFile` to the logger
        """
        self.targets.append(target)
        self._calcLowestTarget()

    def removeTarget(self, target):
        """Remove a target, typically a :class:`~log.LogFile` from the logger
        """
        if target in self.targets:
            self.targets.remove(target)
        self._calcLowestTarget()

    def _calcLowestTarget(self):
        self.lowestTarget = 50
        for target in self.targets:
            self.lowestTarget = min(self.lowestTarget, target.level)

    def log(self, message, level, t=None, obj=None):
        """Add the `message` to the log stack at the appropriate `level`

        If no relevant targets (files or console) exist then the message is
        simply discarded.
        """
        # check for at least one relevant logger
        if level < self.lowestTarget:
            return
        # check time
        if t is None:
            global defaultClock
            t = defaultClock.getTime()
        # add message to list
        self.toFlush.append(
            _LogEntry(t=t, level=level, message=message, obj=obj))

    def flush(self):
        """Process all current messages to each target
        """
        # loop through targets then entries in toFlush
        # so that stream.flush can be called just once
        formatted = {}  # keep a dict - so only do the formatting once
        for target in self.targets:
            for thisEntry in self.toFlush:
                if thisEntry.level >= target.level:
                    if not thisEntry in formatted:
                        # convert the entry into a formatted string
                        formatted[thisEntry] = self.format % thisEntry.__dict__
                    target.write(formatted[thisEntry] + '\n')
            if hasattr(target.stream, 'flush'):
                target.stream.flush()
        # finished processing entries - move them to self.flushed
        self.flushed.extend(self.toFlush)
        self.toFlush = []  # a new empty list

root = _Logger()
console = LogFile()


def flush(logger=root):
    """Send current messages in the log to all targets
    """
    logger.flush()
# make sure this function gets called as python closes
atexit.register(flush)


def critical(msg, t=None, obj=None):
    """log.critical(message)
    Send the message to any receiver of logging info (e.g. a LogFile)
    of level `log.CRITICAL` or higher
    """
    root.log(msg, level=CRITICAL, t=t, obj=obj)
fatal = critical


def error(msg, t=None, obj=None):
    """log.error(message)

    Send the message to any receiver of logging info (e.g. a LogFile)
    of level `log.ERROR` or higher
    """
    root.log(msg, level=ERROR, t=t, obj=obj)


def warning(msg, t=None, obj=None):
    """log.warning(message)

    Sends the message to any receiver of logging info (e.g. a LogFile)
    of level `log.WARNING` or higher
    """
    root.log(msg, level=WARNING, t=t, obj=obj)
warn = warning


def data(msg, t=None, obj=None):
    """Log a message about data collection (e.g. a key press)

    usage::
        log.data(message)

    Sends the message to any receiver of logging info (e.g. a LogFile)
    of level `log.DATA` or higher
    """
    root.log(msg, level=DATA, t=t, obj=obj)


def exp(msg, t=None, obj=None):
    """Log a message about the experiment
    (e.g. a new trial, or end of a stimulus)

    usage::
        log.exp(message)

    Sends the message to any receiver of logging info (e.g. a LogFile)
    of level `log.EXP` or higher
    """
    root.log(msg, level=EXP, t=t, obj=obj)


def info(msg, t=None, obj=None):
    """Log some information - maybe useful, maybe not

    usage::
        log.info(message)

    Sends the message to any receiver of logging info (e.g. a LogFile)
    of level `log.INFO` or higher
    """
    root.log(msg, level=INFO, t=t, obj=obj)


def debug(msg, t=None, obj=None):
    """Log a debugging message (not likely to be wanted once
    experiment is finalised)

    usage::
        log.debug(message)

    Sends the message to any receiver of logging info (e.g. a LogFile)
    of level `log.DEBUG` or higher
    """
    root.log(msg, level=DEBUG, t=t, obj=obj)


def log(msg, level, t=None, obj=None):
    """Log a message

    usage::
        log(level, msg, t=t, obj=obj)

    Log the msg, at a  given level on the root logger
    """
    root.log(msg, level=level, t=t, obj=obj)