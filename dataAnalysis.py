from cili.util import *
from cili.cleanup import *
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image
from matplotlib.colors import LinearSegmentedColormap
from win32api import GetSystemMetrics # Assuming test is performed on same size laptop!!!
import os

def loadData():

    # Collect samps frames from the example files
    samps, events = load_eyelink_dataset('sample_data/bino1000.asc')

    # Clean the data using cili's built-in functions
    samps = interp_eyelink_blinks(samps, events, interp_fields=['pup_l'])
    samps = interp_zeros(samps, interp_fields=['pup_l'])
    samps = butterworth_series(samps, fields=['pup_l'])
    # Convert panda dataframes to numpy arrays because that what Thomas knows
    # Assuming we have data from both eyes
    samps = samps.values
    pos_l = samps[:, 0:2]; pup_l = samps[1:,2]
    # Position is a 2D array where each entry corresponds to [x, y]

    pos = pos_l     # Only consider left eye (for now?)

    # Import all the images containing the characters 'face' and choose a random one

    faces = []
    for imagePath in os.listdir('images'):
        if 'face' in imagePath:
            faces.append(imagePath)
    backgroundImage = Image.open('images/' + np.random.choice(faces))

    return backgroundImage, pos

# Call loadData() and save results
backgroundImage, pos = loadData()   # Eventually this could use inputs to specify data

def getHeatMap():
    global backgroundImage, pos
    #===============================================================
    # returns a 2D matrix where each position corresponds to a 'heat'
    h, w = backgroundImage.size # Returns the size in pixels
    # Create a mesh grid over the entire space
    x_gridpoints = w
    y_gridpoints = h
    mesh = np.zeros((x_gridpoints, y_gridpoints))
    # Define the width and height of each grid point
    MIN_X = np.min(pos[:,0])
    MAX_X = np.max(pos[:,0])
    MIN_Y = np.min(pos[:,1])
    MAX_Y = np.max(pos[:,1])

    pos[:,0] = (pos[:,0] - MIN_X)*(w/MAX_X)
    pos[:,1] = (pos[:,1] - MAX_Y)*(h/MAX_Y)

    dx = MAX_X/x_gridpoints
    dy = MAX_Y/y_gridpoints

    for loc in pos:
        try:
            xGrid = int(loc[0]//dx)
            yGrid = int(loc[1]//dy)
            mesh[xGrid-5:xGrid+5, yGrid-5:yGrid+5] += 1     # Increment the area around the grid point containing the point
        except IndexError as e:
            print('Index error because of location ' + str(loc))
            continue

    #===============================================================

    ncolors = 256
    color_array = plt.get_cmap('hot')(range(ncolors))
    # change alpha values
    color_array[:,-1] = np.linspace(1.0,0.0,ncolors)
    # create a colormap object
    map_object = LinearSegmentedColormap.from_list(name='hot_alpha',colors=color_array[::-1])
    # register this new colormap with matplotlib
    plt.register_cmap(cmap=map_object)

    fig, ax = plt.subplots()
    ax.imshow(backgroundImage)
    cb = ax.contourf(mesh, cmap='hot_alpha')
    plt.colorbar(cb)

    plt.show()


getHeatMap()
