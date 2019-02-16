from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze import eyetracker
from win32api import GetSystemMetrics
import sys
import pylink
import os



def main(imagePath):
	# start timing
	libtime.expstart()
	# create keyboard object
	kb = keyboard.Keyboard()
	# display and screen object
	disp = display.Display(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
	scr = screen.Screen(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])

	tracker = pylink.EyeLink("100.1.1.1")

	# eyelink calibration
	#eyetracker.calibrate()

	scr.draw_image(imagePath, colour=col, pos=pos, fontsize=84)
	disp.fill(scr)


	while kb.get_key()[0] == None:
		pass # Do nothing


	disp.close()

main('images/white_background.jpg')
