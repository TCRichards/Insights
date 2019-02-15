from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker
from win32api import GetSystemMetrics
import numpy as np

docs = np.array(['Crabs run to the sea.\nCrabs lay eggs.\nCrabs go home.\nLand crabs cannot swim.\n\nCrabs walk.\nCrabs run.\nMom crabs.\nTons of crabs.\n\nHard red crab.\nTaxi cab.\nFlat crab.\nFlat cab.'])

def main():
    global docs

    libtime.expstart()
	# create keyboard object
    kb = keyboard.Keyboard()
	# display and screen object
    disp = display.Display()
    scr = screen.Screen()
    text = np.random.choice(docs)

    '''
	Wait to initilaze eye tracker until plugged in
	# create eyelink object
	eyetracker = EyeTracker(disp)

	# eyelink calibration
	eyetracker.calibrate()
	'''
    #scr.set_background_colour(colour=(0,255,0))

    scr.draw_text(text=text,fontsize=40)

    #draw_fixation(fixtype='cross', colour=None, pos=None, pw=1, diameter=12)

    disp.fill(scr)
    disp.show()
	# reset screen
    while kb.get_key()[0] == None:
        continue
    disp.close()
    scr.clear()


main()
