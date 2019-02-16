from pygaze import libtime
from pygaze import display, screen, keyboard
from pygaze.eyetracker import EyeTracker
from win32api import GetSystemMetrics
import numpy as np

# Example text
docs = np.array(['Crabs run to the sea.\nCrabs lay eggs.\nCrabs go home.\nLand crabs cannot swim.\n\nCrabs walk.\nCrabs run.\nMom crabs.\nTons of crabs.\n\nHard red crab.\nTaxi cab.\nFlat crab.\nFlat cab.',
'The crabs get to the sea.\nThey go in the water.\nThey lay eggs.\nThey go home.\n\nThese crabs live in Cuba.\nThey are land crabs.\nThey live on land.\nThey do not swim.\n\nThe crabs walk to the sea.\nThere are crabs on the grass.\nThere are crabs in the street.\nThey have hard shells.',
'The Oregon Trail was a pathway across the United States that led from east to west.\nThe untamed west offered the promise of new opportunities, the American Dream.\nPeople living in the east wanted the chance to start big farms and find their fortunes.\nWhole families emigrated, or moved, from east to west following the Oregon Trail.\nThey piled all their belongings into a wagon and started their 2,000-mile journey.\nThey were known as pioneers.\n\nPioneers are the first people to move into and settle a region.\nMost of the pioneers walked the entire way across the Oregon Trail, often barefoot.\nTheir wagons were too heavy for horses to pull so they used strong oxen or cattle.\nThe going was slow and rough.'
])

def main():
    global docs

    libtime.expstart()
	# create keyboard object
    kb = keyboard.Keyboard()
	# display and screen object
    disp = display.Display(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
    scr = screen.Screen(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
    text = np.random.choice(docs)

    '''
	Wait to initilaze eye tracker until plugged in
	# create eyelink object
	eyetracker = EyeTracker(disp, trackertype='eyelink',logfile='Results')

	# eyelink calibration
	eyetracker.calibrate()


	'''

    font = 40
    if text == docs[2]:
        font = 28
    scr.draw_text(text=text,fontsize=font)

    disp.fill(scr)
    disp.show()
	# reset screen
    while kb.get_key()[0] == None:
        continue
    disp.close()
    scr.clear()


main()
