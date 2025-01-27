import numpy as np

lst8 = [1,-2,3,-4,5,-6,7,-8]
arr8 = np.array(lst8)
print(arr8)
msk8 = (arr8>=-2) & (arr8<=5)
print(msk8)



lst9 = [1,-2,3,-4,5,-6,7,-8]
arr9 = np.array(lst9).reshape(2,4) #reshape to 2d array 2 row and 4 coloum 
print(arr9)
#The NumPy functions `any()` or `all()` allow for checking if any or all array elements along a given axis satisfy a certain condition, respectively.
print(np.any(arr9>5,axis=0))
print(np.all(arr9>-5,axis=1))