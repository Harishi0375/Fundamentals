import timeit
import numpy as np

lst = list(range(1000))

print(timeit.timeit(lambda: [k*2 for k in lst], number=10000))

# The utility timeit.timeit from this package returns
# the time spent in seconds on the operation performed 
# as many times as the value of the parameter number 
# provided to it. The default value of number is 1 million.
# This means that the utility performs 1 million times the 
# operation that we are interested in and reports the time. 
# For our use, we will take number to be 10,000. Here is the listing.


# similar example
# Define the code snippet to be timed
code_snippet = """
result = 0
for i in range(1000):
    result += i
"""

# Measure the execution time of the code snippet
execution_time = timeit.timeit(code_snippet, number=10000)