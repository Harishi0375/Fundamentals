# addition and subtraction
import numpy as np

arr1 = np.array([[1,2,3],[3,2,1]])

arr2 = np.ones((2,3))

print(arr1, "\n")
print(arr1 + arr2, "\n")
print(arr1 - arr2)

#Multiplication and Division (Component or Element wise)


arr1 = np.array([[1,2,3],[3,2,1]])

print(arr1, "\n")
print(arr1 * arr1, "\n")
print(arr1 / arr1)

#Transpose

arr1 = np.random.rand(2,3,4)

print(arr1, "\n")
print(arr1.T)

#Matrix Multiplication

arr1 = np.array([[1,2,3],[4,5,6]])
arr2 = np.array([[1,0,0],[0,2,0],[0,0,3]])

print(arr1, "\n")
print(arr2, "\n")
print(arr1 @ arr2)

#broadcasting
arr = np.arange(5)

print(arr, "\n\n")
print(arr + 2) #adds +2 to each element in the array

#advanced linear algebra opeartions

x = np.array([[1,2],[3,4]])

print(np.linalg.det(x), "\n")
print(np.linalg.inv(x), "\n")
print(x @ np.linalg.inv(x)) #x * x^-1
# #For two dimensional arrays treated as matrices for 
# computations, numpy.linalg provides tools from finding 
# determinants, inverses to matrix decompositions.
# Let us consider a matrix, and find its inverse.

#Custom NumPy Array Functions
import numpy as np

arr1 = np.array([[1,2],
                 [3,4]])

arr2 = np.array([[4,3],
                 [2,1]])


def linear_comb(x,y):
    return 2*x+y

np.vectorize(linear_comb)

linear_comb(arr1, arr2)
print(linear_comb(arr1,arr2))