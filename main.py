from tkinter import *
# Import the tests
import animation, imageWorker, reading, face, analysisLauncher
import numpy as np
import os


# Instantiate the tkinter master object
root = Tk()
#=================================
# Opens the image configuration program
def viewImages():
    imageWorker.main()

#==================================
# Runs the tests in a new fullscreen window
def startAnimation():
    animation.main()

def startReading():
    images = [] # Store images corresponding to the correct test
    for readingImagePath in os.listdir('images'):
        if 'reading' in readingImagePath and ('.jpg' in readingImagePath or '.png' in readingImagePath):
            images.append('images/'+readingImagePath)

    faceImagePath = np.random.choice(images)
    reading.main(readingImagePath)

def startFace():
    images = [] # Store images corresponding to the correct test
    for faceImagePath in os.listdir('images'):
        if 'face' in faceImagePath and ('.jpg' in faceImagePath or '.png' in readingImagePath):
            images.append('images/'+readingImagePath)
    faceImagePath = np.random.choice(images)
    face.main(faceImagePath)

def startAnalysis():
    analysisLauncher.loadLists()

def startup():
    global root

    #====================================================
    # Add buttons to perform each task

    animationButton = Button(root, text='Animation', command = startAnimation)
    readingButton = Button(root, text='Reading', command = startReading)
    imageButton = Button(root, text='View Images', command = viewImages)
    faceButton = Button(root, text='Face Test', command = startFace)
    analyzeButon = Button(root, text='Perform Analysis',command = startAnalysis)

    animationButton.pack()
    readingButton.pack()
    imageButton.pack()
    analyzeButon.pack()
    faceButton.pack()

    mainloop()

startup()
