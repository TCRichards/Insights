from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker

import random

# # # # #
# prep

# start timing
libtime.expstart()

# create keyboard object
keyboard = keyboard.Keyboard()

# display object
disp = display.Display()

# create eyelink object
eyetracker = EyeTracker(disp)

# eyelink calibration
eyetracker.calibrate()

while kb.get_key()[0] == None:
	# colour
	col = (random.randint(0,255), random.randint(0,255), random.randint(0,255))
	# position
	pos = (random.randint(0,DISPSIZE[0]), random.randint(0,DISPSIZE[1]))
	# text
	scr.draw_text(text=MESSAGE, colour=col, pos=pos, fontsize=84)
	# display
	disp.fill(scr)
	disp.show()
	# reset screen
	scr.clear()

# stop the madness
disp.close()

# stop the madness
