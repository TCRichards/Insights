from cili.util import *
from cili.cleanup import *
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image
from matplotlib.colors import LinearSegmentedColormap
from win32api import GetSystemMetrics # Assuming test is performed on same size laptop!!!
import os
from pygazeanalyser import gazeplotter
import scipy.stats


def loadData():
    # Collect samps frames from the example files
    samps, events = load_eyelink_dataset('sample_data/bino1000.asc')
    # Store event information about fixation and saccade
    fixation = events.dframes['EFIX']; saccade = events.dframes['ESACC']

    # Not using but could access 'start', 'end', 'msg' data as well

    # Clean the data using cili's built-in functions
    samps = interp_eyelink_blinks(samps, events, interp_fields=['pup_l'])
    samps = interp_zeros(samps, interp_fields=['pup_l'])
    samps = butterworth_series(samps, fields=['pup_l'])
    # Convert panda dataframes to numpy arrays because that's what Thomas knows
    # Assuming we have data from both eyes
    samps = samps.values
    pos_l = samps[:, 0:2]; pup_l = samps[1:,2]
    # Position is a 2D array where each entry corresponds to [x, y]

    pos = pos_l             # Only consider left eye (for now?)

    # Import all the images containing the word 'face' and choose a random one


    return pos, fixation, saccade # note that fixation and saccade are dframes

# Actually perform the data analysis
# @POS = numpy array of positions stored (x,y)
# @FIX = dataframe of fixations
# @SACC = dataframe array of saccades
def analyze(testName, POS, FIX, SACC):

    # We'll need gaussian distributions later
    def gaussian(x, mu, sig):
        return (1/(sig*np.sqrt(2*np.pi)))*np.exp(-.5*np.power((x - mu)/sig, 2.))

    def reverseGaussian(y, mu, sig):
        return np.sqrt(-np.log(2(sig**2*y/mu)))
    # Calculate probability from normal distribution

    if testName == 'reading':
        sentences = 12 # Both of our examples have 12 sentences
        '''
        Let's assume fixation times follow a normal distribution
        Mean times and SD are taken from https://www.sciencedirect.com/science/article/pii/S0093934X03004012
        MFD -> Mean fixation duration (ms)
        FPN -> Fixations per item (sentence)
        '''
        good_MFD = 192
        sigma_good_MFD = 34
        good_FPN = 0.83
        sigma_good_FPN = 0.20

        poor_MFD = 367
        sigma_poor_MFD = 132
        poor_FPN = 1.53
        sigma_poor_FPN = 0.20

        leftEyeFrame = FIX.loc[FIX['eye'] == 'L'] # Filter only the rows for the left eye
        durations = leftEyeFrame['duration'].values
        positions = leftEyeFrame.values[:,4:6]

        my_MFD = np.mean(durations)
        sigma_my_MFD = np.std(durations)

        # Generate two fictitious 'datasets' using a normal distribution
        good_dist = np.array([])
        poor_dist = np.array([])
        my_dist = np.array([])

        x = np.arange(100, 500, 1)
        plt.plot(x, gaussian(x, good_MFD, sigma_good_MFD), label='Normal Readers')
        plt.plot(x, gaussian(x, poor_MFD, sigma_good_MFD), label='Dyslexic Readers')
        plt.plot(x, gaussian(x, my_MFD, sigma_good_MFD), label='Results')
        plt.title('Fixation Times Relative to Study')
        plt.xlabel('Mean Fixation Time (ms)')
        plt.ylabel('Probability')
        plt.legend()
        plt.show()

    elif testName == 'face':
        print('analyzing face results')
    elif testName == 'animation':
        print('analyzing animation results')
    else:
        print("Invalid test name '%s'", testName)

def main():
    # Call loadData() and save results
    pos, fixations, saccade = loadData()   # Eventually this could use inputs to specify data

    leftEyeFrame = fixations.loc[fixations['eye'] == 'L'] # Filter only the rows for the left eye
    durations = leftEyeFrame['duration'].values
    xPositions = leftEyeFrame['x_pos'].values
    yPositions = leftEyeFrame['y_pos'].values
    fixDurations = leftEyeFrame['duration'].values

    faces = []
    for imagePath in os.listdir('images'):
        if 'face' in imagePath and ('.jpg' in imagePath or '.png' in imagePath):
            faces.append(imagePath)
    backgroundImage = Image.open('images/' + np.random.choice(faces))

    """
    fix		-	a dict with three keys: 'x', 'y', and 'dur' (each contain
                a numpy array) for the x and y coordinates and duration of
                each fixation
    """

    fix = {
        'x': xPositions,
        'y': yPositions,
        'dur': fixDurations
        }

    fig = gazeplotter.draw_heatmap(fix, [GetSystemMetrics(1), GetSystemMetrics(0)], imagefile='images/musk_face.jpg')
    plt.show()


    analyze('reading', pos, fixations, saccade)


main()
