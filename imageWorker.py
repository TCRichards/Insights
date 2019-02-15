from PIL import Image
from tkinter import *
from pygaze import screen
import os


def openImage():
    path = listbox.curselection()
    master.delete()
    print(path)

def main():
    global listbox
    for imagePath in os.listdir('images'):
        listbox.insert(END, imagePath)
    mainloop()

master = Tk()
listbox = Listbox(master, selectmode=SINGLE)
listbox.pack()
selectButton = Button(master,text='select',command=openImage)
selectButton.pack()

while kb.get_key()[0] == None:
    continue # Intenional infinite loop
scr.clear()
disp.dispose()


main()
