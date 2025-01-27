#SQL-style DataFrame Joins

# To join two DataFrames as SQL tables you can use pd.merge
#  function. This function has exactly the same functionality
# as the join function in SQL.

import pandas as pd
import numpy as np

df1 = pd.DataFrame({
    "key": np.random.choice(range(10), 7, replace=False),
    "data1": np.arange(7)
})
df2 = pd.DataFrame({
    "key": np.random.choice(range(10), 5, replace=False),
    "data2": np.arange(5)
})

print(df1)
print("------------")
print(df2)
print("------------")

#merge data
#only merges till same index
mergedata = pd.merge(df1, df2)
print(mergedata)
print("------------")

#specify the column directly to avoid any confusion 
print(pd.merge(df1, df2, on='key'))
print("------------")

#If DataFrames have different column names that we
#want to join on, we can specify the column name for each of them separately.

df2 = df2.rename(columns={'key': 'new_key'})
mergedata = pd.merge(df1, df2, left_on='key', right_on='new_key')
print(df2) #just to verify
print("------------")
print(mergedata)
print("------------")

# It is also possible to join DataFrames on index. To do in it is enough to 
# add left_index=True or right_index=True depending on which table indexes to use.
df2 = df2.set_index('new_key')
mergedata = pd.merge(df1, df2, left_on='key', right_index=True)
print(mergedata)
print("------------")


# Concatenating data along an axis
a = np.random.randint(10, size=(4, 3))
b = np.random.randint(10, size=(2, 3))
print(a)
print("------------")
print(b)
print("------------")

#concatenate
concatenate = np.concatenate((a, b))
print(concatenate)
print("------------")


# In case of pd.DataFrame of pd.Series, 
# the same operation can be performed with pd.concat method.

a = pd.DataFrame(a)
b = pd.DataFrame(b)
print(a)
print("------------")
print(b)
print("------------")

print(pd.concat((a, b), axis=1))
print("------------")
print(pd.concat((a, b), axis=0))
print("------------")

#However, we can avoid it by adding join argument, 
#which inherits the behaviour of the pd.merge.

print(pd.concat((a, b), axis=0, join="inner"))
print("------------")

# If for some reason we want to distinguish the 
# original DataFrames from the concatenated ones,
# we can specify keys argument with key names for
# each of DataFrames.

print(pd.concat([a, a, a], keys=["one", "two", "three"]))
