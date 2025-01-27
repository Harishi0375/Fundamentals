import pandas as pd

mulind = pd.MultiIndex.from_product([['x','y'],[-1,1]])
print(mulind)


mulind = pd.MultiIndex.from_arrays([['x','x','y','y'],[-1,1,-1,1]])
#This code creates a multi-index directly from the arrays provided. The resulting multi-index has the same structure as the previous example.
print(mulind)

# print: 
# MultiIndex([('x', -1),
#             ('x',  1),
#             ('y', -1),
#             ('y',  1)],
#            )