from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker
from win32api import GetSystemMetrics

def main():
    libtime.expstart()
	# create keyboard object
    kb = keyboard.Keyboard()
	# display and screen object
    disp = display.Display()
    scr = screen.Screen()

    disp.close()

main()
