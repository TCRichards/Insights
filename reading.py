from win32api import GetSystemMetrics
import numpy as np
from tkinter import *
from PIL import Image, ImageTk


# This doesn't really do anything anymore


def main(imagePath):

    '''
    libtime.expstart()
	# create keyboard object
    kb = keyboard.Keyboard()
	# display and screen object
    disp = display.Display(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])
    scr = screen.Screen(dispsize = [GetSystemMetrics(0), GetSystemMetrics(1)])


	# Wait to initilaze eye tracker until plugged in
	# create eyelink object
    #eyetracker = EyeTracker(disp, trackertype='dummy')

	# eyelink calibration
    #eyetracker.calibrate()

    scr.draw_image(imagePath)

    if not kb.get_key()[0] == None:
        scr.clear()
        disp.close()
        eyetracker.close()
        libtime.expend()

    # start timing
    #libtime.expstart()
    '''

    master = Tk()
    master.geometry('1536x864')
    canvas = Canvas(master)
    readImage = Image.open(imagePath)
    photoImage = ImageTk.PhotoImage(readImage)
    label = Label(canvas, image=photoImage)
    label.image=photoImage
    label.pack()
    #imagesprite = canvas.create_image(GetSystemMetrics(0),GetSystemMetrics(1),image=photoImage)
    mainloop()


main('images/oregontrail_reading_1.jpg')
