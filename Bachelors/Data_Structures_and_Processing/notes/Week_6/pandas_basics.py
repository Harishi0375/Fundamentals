#The pandas library is a powerful and 
# popular Python library used for data 
# manipulation and analysis.

import pandas as pd
print("s1")
x = pd.Series([-4,5,6,10])
print(x)

print("s2")
d1 = {'a':-4, 'b':5, 'c':6, 'd':10 }
x = pd.Series(d1)
print(x)
print(x['a'])

x.array  #returns the elements stored in it 

x.index 

print("s3")
lst = [-4, 5, 6, 10]
idx = ['a', 'b', 'c', 'd']
x = pd.Series(lst, index=idx)
print(x)

print("s4")
d1 = {'a':-4, 'b':5, 'c':6, 'd':10 }
idx = ['A', 'b', 'C', 'D']
x = pd.Series(d1, index=idx)
print(x)
# A': NaN (because 'A' doesn't exist in the original dictionary)
# 'b': 5.0 (because 'b' exists in the original dictionary with a value of 5)
# 'C': NaN (because 'C' doesn't exist in the original dictionary)
# 'D': NaN (because 'D' doesn't exist in the original dictionary)


#modifying index of a series 
print("s5")
lst = [-4, 5, 6, 10]
x = pd.Series(lst)
print(x)
print("Let us change the index now.")
idx = ['a', 'b', 'c', 'd']
x.index = idx
print(x)

dir