import matplotlib . pyplot as plt
import numpy as np

fig , ax = plt. subplots () # Create a figure containing a single axes
                            # create two ndarray data type in numpy :
xpoints = np. array ([1 , 2, 6, 8])
ypoints = np. array ([3 , 8, 1, 10])

# call functions in matplotlib to create and draw graph :
ax. plot ( xpoints , ypoints )
plt. show ()