'''
I tried writing my own heatmap code that didn't really work,
but I was too proud of it to toss it completely, so here it will
live ad infinitum

'''



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
