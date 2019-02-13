# example script for using PyGaze

# # # # #
# importing the relevant libraries
import time
import numpy
import constants
from pygaze import screen, display, keyboard
from pygaze import eyetracker
from pygaze import logfile

# # # # #
# benchmark

RUNS = 1001

# # # # #
# experiment setup

# create display object
disp = display.Display()

# create eyetracker object
tracker = eyetracker.EyeTracker(disp)

# create keyboard object
keyboard = keyboard.Keyboard(keylist=['space'], timeout=None)

# Logfile
log = logfile.Logfile()

# create screens
scr = screen.Screen()

# # # # #
# run the experiment

# calibrate eye tracker
tracker.calibrate()

# start eye tracking
tracker.start_recording()
tracker.status_msg("now running")
tracker.log("start %d" % (time.clock()))

# show dot at gaze position until spacepress
timestamps = numpy.zeros(RUNS)
t = time.clock()
for i in range(RUNS):
	timestamps[i] = t
	scr.clear()
	gazepos = tracker.sample()
	scr.draw_fixation(fixtype='dot',pos=(int(gazepos[0]),int(gazepos[1])))
	disp.fill(screen=scr)
	disp.show()
	t = time.clock()

# stop eye tracking
tracker.stop_recording()

# close connection to the tracker
tracker.close()

# intersampletime
intersampletime = numpy.zeros(RUNS-1)
for i in range(RUNS-1):
	intersampletime[i] = (timestamps[i+1] - timestamps[i])*1000
	log.write([intersampletime[i]])
M = numpy.mean(intersampletime)
SD = numpy.std(intersampletime)
print("intersampletime: M=%s, SD=%s" % (M,SD))

# end the experiment
log.close()
disp.close()
