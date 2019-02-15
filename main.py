from tkinter import *
import animation, imageWorker, reading


# Instantiate the tkinter master object
root = Tk()
menu = Menu(root)
#=================================
# Opens the image configuration program
def configureImage():
    imageWorker.main()

#==================================
# Runs the example exercise in a new fullscreen window
def startAnimation():
    animation.main()

def startReading():
    reading.main()

def startFace():
    face.main()
    
#===================================
# Commands for a File tab in the window
def NewFile():
    print ("New File!")
def OpenFile():
    name = askopenfilename()
    print(name)
def About():
    print ("This is a simple example of a menu")
#===================================

def startup():
    global root, menu

    root.config(menu=menu)
    filemenu = Menu(menu)
    menu.add_cascade(label="File", menu=filemenu)
    filemenu.add_command(label="New", command=NewFile)
    filemenu.add_command(label="Open...", command=OpenFile)
    filemenu.add_separator()
    filemenu.add_command(label="Exit", command=root.quit)

    helpmenu = Menu(menu)
    menu.add_cascade(label="Help", menu=helpmenu)
    helpmenu.add_command(label="About...", command=About)

    animationButton = Button(root, text='Animation', command = startAnimation)
    readingButton = Button(root, text='Reading', command = startReading)
    imageButton = Button(root, text='View Images', command = configureImage)
    faceButton = Button(root, text='Face Test', command = startFace)


    animationButton.pack()
    readingButton.pack()
    imageButton.pack()

    mainloop()

startup()
