from PIL import Image
from tkinter import *
from pygaze import screen
import os

'''
All that this class does is provide a list of images present to the UI when called from main.py
'''

def openImage():
    path = listbox.curselection()
    master.delete()
    print(path)

def main():
    global listbox
    for imagePath in os.listdir('images'):
        if '.jpg' in imagePath or '.png' in imagePath:
            listbox.insert(END, imagePath)
    mainloop()

master = Tk()
listbox = Listbox(master, selectmode=SINGLE)
listbox.pack()
#selectButton = Button(master,text='select',command=openImage)
#selectButton.pack()
