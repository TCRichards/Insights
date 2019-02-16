from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker
from win32api import GetSystemMetrics
from time import sleep
import cv2
import numpy as np
import random


def main():

	# create keyboard object
	#kb = keyboard.Keyboard()

	#disp = display.Display(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
	#scr = screen.Screen(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
	# display and screen object
	# Wait to initilaze eye tracker until plugged in
	# create eyelink object
	# eyelink_tacker = pylink.EyeLink("100.1.1.1")
	# eyetracker = EyeTracker(disp)
	# eyelink calibration
	# eyetracker.calibrate()

	# Load a yoga and geometry video
	yoga = cv2.VideoCapture('images/yoga_video_1.avi')
	shapes = cv2.VideoCapture('images/geometry_video_1.avi')


	# start timing
	libtime.expstart()

	while(True):
	    # Capture frame-by-frame
		ret1, frame1 = yoga.read()
		ret2, frame2 = shapes.read()

		colored_vid1 = cv2.cvtColor(frame1, cv2.IMREAD_COLOR)
		colored_vid2 = cv2.cvtColor(frame2, cv2.IMREAD_COLOR)

		# listen for a keypress and close when 'q' is pressed
		if cv2.waitKey(1) & 0xFF == ord('q'):
			break

		matrix = np.hstack((colored_vid1, colored_vid2))
	    # Display the resulting frame
		cv2.imshow('video', matrix)
		cv2.setWindowProperty('video', cv2.WND_PROP_FULLSCREEN, 1)

		sleep(0.02)


	# When everything done, release the capture
	cv2.destroyAllWindows()
