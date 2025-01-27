from sys import displayhook
import numpy as np
import matplotlib.pyplot as plt

import pandas as pd

### Hierarchical indexing -----------------------------------------------------------------------------

#### MultiIndex objects

#In the cell below, a DataFrame is constructed and displayed.

res1 = pd.DataFrame( {'1970':[592533,502432,696419,634202],
                      '1990':[551219,490571,626973,579988],
                      '2010':[547340,523058,574635,606588]},
                    index=['Bremen','Dresden','Essen','Stuttgart'])
displayhook(res1)
print(res1.index)

res2 = res1.stack()
displayhook(res2)
#The result `res2` is a Pandas Series. The four rows of `res1` have been stacked to form a one-dimensional array, i.e., a single column vector of data. As revealed by `res2.index`, the index has become a set of tuples, a so-called `MultiIndex` object.

print(res2.index) #prints: Index(['Bremen', 'Dresden', 'Essen', 'Stuttgart'], dtype='object')  

# The `stack()` operation is reversed through `unstack()`. The resulting object `res3` is a DataFrame with the same format and the same content as the initial DataFrame `res1`.

res3 = res2.unstack()
displayhook(res3)
print(res3.index)


#MultiIndex objects can be defined in several ways. If individual tuple elements are separate columns of a data file, they can be stored in arrays which in turn yields a MultiIndex object through the `from_arrays()` method. Together with the column vector of data from the same file, a Series object just as `res2` can then be constructed from the MultiIndex.

cities = ['Bremen', 'Bremen', 'Bremen', 'Dresden', 'Dresden', 'Dresden', 
          'Essen', 'Essen', 'Essen', 'Stuttgart', 'Stuttgart', 'Stuttgart']
print('Array of city names:')
print(cities)
years = [1970, 1990, 2010, 1970, 1990, 2010, 
         1970, 1990, 2010, 1970, 1990, 2010]
print('\nArray of years:')
print(years)
mulind4 = pd.MultiIndex.from_arrays([cities,years])
print('\nMultiIndex constructed from the two arrays:')
print(mulind4)


#With the resident numbers provided as a single vector, a suitable Series object is created using the MultiIndex.

residents = [592533,551219,547340,502432,490571,523058,
             696419,626973,574635,634202,579988,606588]
print('Array of resident numbers:')
print(residents)
res4 = pd.Series(residents,index=mulind4)
print('\nSeries constructed from MultiIndex and array of resident numbers:')
print(res4)
print('\nUnstacking the Series produces the following DataFrame:')
displayhook(res4.unstack())


#Rows and columns are swapped through the application of `transpose()`.
displayhook(res4.transpose().head())

#The `describe()` method yields summary statistics of a DataFrame.
displayhook(res4.describe().transpose().head())

## GroupBy mechanism -----------------------------------------------------------------------

# The GroupBy mechanism is usually understood as a sequence of three operations.
# 1. *Split* a DataFrame according to the values of a specific key to produced groups.
# 2. *Apply* a function (aggregation, transformation, filtering, ...) within each group. 
# 3. *Combine* the results into an array.

#Split - apply - combine

import pandas as pd

# Sample DataFrame
data = {'Category': ['Electronics', 'Clothing', 'Electronics', 'Clothing', 'Electronics'],
        'Product': ['Laptop', 'Shirt', 'Smartphone', 'Jeans', 'Headphones'],
        'Price': [1200, 25, 800, 50, 100]}

df = pd.DataFrame(data)

print("Original DataFrame:")
print(df)

# Grouping by 'Category'
grouped_data = df.groupby('Category')


# Applying an aggregate function (e.g., sum) to each group
sum_by_category = grouped_data.sum()

print("\nGrouped Data - Sum by Category:")
print(sum_by_category)


#example 2

import pandas as pd

# Sample DataFrame
data = {'Category': ['Electronics', 'Clothing', 'Electronics', 'Clothing', 'Electronics'],
        'Product': ['Laptop', 'Shirt', 'Smartphone', 'Jeans', 'Headphones'],
        'Price': [1200, 25, 800, 50, 100]}

df = pd.DataFrame(data)

print("Original DataFrame:")
print(df)

# Grouping by 'Category'
grouped_data = df.groupby('Category')


# Applying multiple aggregate functions to each group
agg_result = grouped_data.aggregate({'Price': ['sum', 'mean']})

print("\nAggregated Data:")
print(agg_result)



#piviot tables -------------------------------------------------------------------------

#  A pivot table allows you to rearrange and aggregate data, providing a more organized and insightful view. Let's explore how to create a pivot table using pandas in Python:

import pandas as pd

# Sample DataFrame
data = {'Category': ['Electronics', 'Clothing', 'Electronics', 'Clothing', 'Electronics'],
        'Product': ['Laptop', 'Shirt', 'Smartphone', 'Jeans', 'Headphones'],
        'Price': [1200, 25, 800, 50, 100]}

df = pd.DataFrame(data)

print("Original DataFrame:")
print(df)

# Creating a pivot table
pivot_table = df.pivot_table(values='Price', index='Category', columns='Product', aggfunc='sum', fill_value='NULL')
#fill_value='NULL': Fills any missing values with 'NULL'.
print("\nPivot Table:")
print(pivot_table)






