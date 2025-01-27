import numpy as np
print('sin(pi/2) = {}'.format(np.sin(np.pi/2)))

lst1 = [2,3,5,7]
print(lst1,type(lst1))
arr1 = np.array(lst1)
print(arr1,type(arr1))
print('dtype of arr1   : ',arr1.dtype)

# import numpy as np

arr = np.arange(2,9) #creates 2 to 8
print(arr)
arr[arr%3==2] = 1
print(arr%3)

arr = np.array([1,-2,-3,4,-5,6]).reshape(2,3) #reshape to 2 rows and 3 columns
print(arr)

arr = np.array(3*[[2,3]])
print(arr)

print(arr.argmax(axis=0)) #0 for row and 1 for column

arr = np.array([2.0,4j,6]) #this is complex numbers
print(arr)

#ways to print 1D or 2D arrays
mat = np.full((4,5),(6,))
mat = np.full((4,5),6)
print(mat)
print('\n')
mat = np.ones((4,5),dtype = int) #array filled with ones

mat = 6*np.ones((4,5),dtype = int) #array filled with 6 * 1 = 6



print(mat)

### Using np.full(), print a uniform NumPy array of shape (2,5) filled with the string 'xyz'.
print(np.full((2,5),'xyz'))
### Using np.ones(), print a uniform NumPy array of shape (3,2) filled with the float -4.32.
print(-4.32*np.ones((3,2)))
### Using np.arange(), print the one-dimensional integer array [13,11,9,7,5] (in this order).
print(np.arange(13,3,-2))
### Using np.linspace(), print the one-dimensional floating-point array [9.5,8.0,6.5,5.0] (in this order).
print(np.linspace(9.5,5,4))

arr11 = np.array([[41,43,47,53],[59,61,67,71]])
arr11.reshape(4,2)[0,1] = -3
print(arr11)

arr09 = np.array([[41,43,47,53],[59,61,67,71]])
print(arr09.flatten()) #converts to 1D array

arr10 = np.array([[41,43,47,53],[59,61,67,71]])
arr10.flatten()[-2] = 73
print(arr10)

#The ravel function in NumPy is used to flatten multi-dimensional arrays into a one-dimensional array. It returns a flattened view of the input array, meaning it doesn't create a new array but provides a different view of the existing data.
arr10.ravel()[0] = -42
print(arr10)

