import numpy as np
import matplotlib.pyplot as plt


#Plain text files with such a regular rectangular structure can be loaded, e.g., by means of the NumPy functions ``loadtxt()`` or ``genfromtxt()``. The former function is faster when no data are missing while the latter function works also in the case of missing data.
alldata = np.loadtxt('SN_d_tot_V2.0.txt')

#The data are read from the text file and stored in the two-dimensinal array ``alldata`` (a matrix). You may extract the data from the first two columns (year and sunspot number) into one-dimensional arrays (vectors) as follows.
year = alldata[:,0]
nspots = alldata[:,1]


#One may associate columns more directly with data vectors by means of the keywords `usecols` and `unpack`.
#year,nspots = np.loadtxt('SN_y_tot_V2.0.txt',usecols=(0,1),unpack=True)