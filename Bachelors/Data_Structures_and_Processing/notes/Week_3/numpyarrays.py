import numpy as np              # use of the short np is a convention.

arr = np.array([[1,2,3,4], (5,6,7,8), range(4)])

print(arr)

# -----------------------------------
# [[1 2 3 4]    
#  [5 6 7 8] 
#  [0 1 2 3]]

arr.shape
# ------------------------------------
# (3,4)

arr.ndim #dimension of array

arr.dtype #int64

import numpy as np
import timeit

arr = np.arange(1000)

print(timeit.timeit(lambda: 2 * arr, number=10000))