from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker
from win32api import GetSystemMetrics
import numpy as np

# This doesn't really do anything anymore


def main(imagePath):

    libtime.expstart()
	# create keyboard object
    kb = keyboard.Keyboard()
	# display and screen object
    disp = display.Display(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
    scr = screen.Screen(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])


	# Wait to initilaze eye tracker until plugged in
	# create eyelink object
    eyetracker = EyeTracker(disp, trackertype='dummy')

	# eyelink calibration
    eyetracker.calibrate()

    scr.draw_image(imagePath)

    if not kb.get_key()[0] == None:
        scr.clear()
        disp.close()
        eyetracker.close()
        libtime.expend()
