import numpy as np

# ----------------------------------------
arr = np.random.rand(3,2)

print(arr)

print(arr[0,1])

# -----------------------------------------
arr = np.random.rand(3,2)

print(arr, "\n")

print(arr[1:,:]) #starting from second row and all coloums

#------------------------------------------
arr = np.random.rand(3,2)

print(arr, "\n")

print(arr[0,1:])
#------------------------------------------
arr = np.array([1,2,3,4])
lst = [True, False, False, True]

arr[lst]
#prints [1,4]

#-------------------------------------------
arr = np.random.rand(4,3)
print(arr, "\n\n")

arr[1:3,:] = 1
print(arr)

#--------------------------------------------
