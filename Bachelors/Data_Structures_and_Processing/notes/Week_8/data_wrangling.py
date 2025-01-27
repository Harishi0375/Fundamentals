import pandas as pd
import numpy as np

# multiindex
data = pd.Series(
    np.random.uniform(size=6),
    index=[
        ['a', 'a', 'a', 'b', 'b', 'c'],
        [ 1,   2,   3,   1,   2,   1]
    ]
)

print(data)
print("------------")

print(data['a']) #values of a
print("------------")

print(data.loc[['a','c']]) #to print more than one multiIndex
print("------------")

print(data.loc[:, 2]) #prints position 2 of a,b,c (c does not have)
print("------------")

newdata = data.unstack()
print(newdata)
print("------------")

# example 2 with range 
data2 = pd.Series(
    np.random.uniform(low=1, high=2, size=6),  # Specify low and high parameters
    index=[
        ['a', 'a', 'a', 'b', 'b', 'c'],
        [1, 2, 3, 1, 2, 1]
    ]
)

print(data2)
print("------------")

df = pd.DataFrame(
    np.random.rand(4, 3),
    index=[["a", "a", "b", "b"],
           [1, 2, 1, 2]],
    columns=[["index1", "index1", "index2"],
             ["sub_index1", "sub_index2", "sub_index1"]]
)
print(df)
print("------------")

#When creating DataFrame we can make MultiIndex for both rows 
#and columns. The amount of indices in hierarchy can be arbitrary. 




# check the amount of hierarchy levels for both row indices and columns
print(df.index.nlevels, df.columns.nlevels)
print("------------")


# MultiIndex can be created directly from arrays.​
df.index = pd.MultiIndex.from_arrays(
    [['i1', 'i1', 'i2', 'i2'],
     ['one', 'two', 'one', 'two']]
)
print(df)
print("------------")

#MultiIndex level names
df.index.names = ['key1', 'key2']
print(df)
print("------------")


#swap level names
df.swaplevel("key1", "key2")
print(df)
print("------------")


# if you want to replace MultiIndex with an ordinary index, you can 
# call reset_index function. It will create a column for each level
# of the MultiIndex and add default indices for rows.

df.reset_index()
print(df)
print("------------")

# To return to MultiIndex, you can specify an index by specifying 
# the columns whose values should make up the indexes in the desired order.

df.reset_index().set_index(['key2', 'key1'])
print(df)
print("------------")