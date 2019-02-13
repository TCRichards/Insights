# Display a message on your display until space is pressed
#
# handy for when you're away from your desk and want your
# co-workers to know
#
# E.S. Dalmaijer, 2013

# your message
MESSAGE = "AFK; BRB"

# import stuff
# SOMEBODY USED IMPORT STATEMENTS WRONG HERE
import random
from pygaze.defaults import *
from pygaze import libtime
from pygaze import display, screen, keyboard

# start timing
libtime.expstart()

# objects
disp = display.Display()
scr = screen.Screen()
kb = keyboard.Keyboard(keylist=['space'],timeout=1)

# run annoying message
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
