from PIL import Image
from tkinter import *
from pygaze import screen
import os
import dataAnalysis

'''
All that this class does is provide a list of images present to the UI when called from main.py
'''

def runAnalysis():
    global dataList, testList, imageList, testName, dataPath, imagePath

    imagePath = imageList.get(imageList.curselection())

    if testName == 'animation':
        dataAnalysis.main(testName, dataPath)
    else:
        dataAnalysis.main(testName, dataPath, imagePath)

def continueToImages():
    global testList, imageList, testButton, imageButton, dataPath

    dataPath = dataList.get(dataList.curselection())

    testList.pack_forget()
    testButton.pack_forget()
    imageList.pack()
    imageButton.pack()


def continueToData():
    global testList, dataList, testButton, runButton, testName

    testName = testList.get(testList.curselection())

    testList.pack_forget()
    testButton.pack_forget()
    dataList.pack()
    dataButton.pack()


def loadLists():
    global dataList, testList, imageList

    for dataPath in os.listdir('sample_data'):
        dataList.insert(END, 'sample_data/' + dataPath)
    for imagePath in os.listdir('images'):
        imageList.insert(END, 'images/'  + imagePath)
    for testName in ['face', 'reading', 'animation']:
        testList.insert(END, testName)

    mainloop()


master = Tk()

testList = Listbox(master, width=100,selectmode=SINGLE)
testButton = Button(master, text='Select Test',command=continueToData)
testList.pack()
testButton.pack()

imageList = Listbox(master, width=100,selectmode=SINGLE)
imageButton = Button(master, text='Select Image and Run',command=runAnalysis)


dataList = Listbox(master, width=100,selectmode=SINGLE)
dataButton = Button(master,text='Select Data',command=continueToImages)

testName = ''
dataPath = ''
ImagePath = ''

#loadLists()
