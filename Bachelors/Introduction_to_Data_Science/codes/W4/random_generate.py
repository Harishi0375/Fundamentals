
import numpy as np
### Consider the following two-dimensional array of integer random numbers in the interval [0,10].
arr13 = np.random.randint(11,size=(3,5))
print(arr13)


arr14 = 4+2*np.random.rand(4,5)
print(arr14)


#parameters of arange --> numpy.arange(start,stop-1,step,dtype = something)
y = 1 + np.arange(2,12,3)
print(y)