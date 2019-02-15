from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker
from win32api import GetSystemMetrics
import random

width = GetSystemMetrics(0)
height = GetSystemMetrics(1)

def main():
	# start timing
	libtime.expstart()
	# create keyboard object
	kb = keyboard.Keyboard()
	# display and screen object
	disp = display.Display()
	scr = screen.Screen()

	MESSAGE = 'HELLO WORLD'

	'''
	Wait to initilaze eye tracker until plugged in
	# create eyelink object
	eyetracker = EyeTracker(disp)

	# eyelink calibration
	eyetracker.calibrate()
	'''

	while kb.get_key()[0] == None:
		# colour
		col = (random.randint(0,255), random.randint(0,255), random.randint(0,255))
		# position
		pos = (random.randint(0,width), random.randint(0,height))
		# text
		scr.draw_text(text=MESSAGE, colour=col, pos=pos, fontsize=84)
		# display
		disp.fill(scr)
		disp.show()
		# reset screen
		scr.clear()

	disp.close()
