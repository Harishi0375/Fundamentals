import numpy as np
import pandas as pd

df1 = pd.DataFrame({
    "key": np.random.choice(range(10), 7, replace=False),
    "data1": np.arange(7)
})
df2 = pd.DataFrame({
    "key": np.random.choice(range(10), 5, replace=False),
    "data2": np.arange(5)
})

# reshape data
df1.index.name = 'index'
df1.columns.name = 'content'
print(df1)
print("------------")

# stack each index
print(df1.stack())
print("------------")

# unstack
print(df1.unstack())
print("------------")


# taxi file
data = pd.read_csv('taxi.csv')
print(data.head())
print("------------")

# We can utilize pd.PeriodIndex (which represents
#  time intervals rather than points in time),
# to set the index to consist of datetime values 
# at the end of each month

periods = pd.PeriodIndex(data.pop('pickup_datetime'), freq="s")
data.index = periods.to_timestamp("S")
print(data.head())
print("------------")

data.columns.name = 'item'
long_data = data.stack().reset_index().rename(columns={0: 'value'})
print(long_data)
print("------------")

# The pivot() function reshapes a DataFrame by pivoting 
# the values of one column into a new set of columns based 
# on unique values in another column.

df = pd.DataFrame({
    'Name': ['Alice', 'Bob', 'Charlie', 'Alice', 'Bob', 'Charlie'],
    'Subject': ['Math', 'Math', 'Math', 'Science', 'Science', 'Science'],
    'Score': [80, 85, 75, 90, 88, 85]
})

pivot_df = df.pivot(index='Name', columns='Subject', values='Score')

print(pivot_df)
print("------------")

# to unpiviot 
pivot_df = pd.melt(df,id_vars=['Name'], var_name='Subject', value_name='Score')
print(pivot_df)
print("------------")

# specify a subset of columns to use as value columns in the pd.melt()
import pandas as pd

# Create a sample DataFrame in wide format
wide_df = pd.DataFrame({
    'Name': ['Alice', 'Bob', 'Charlie'],
    'Math': [80, 85, 75],
    'Science': [90, 88, 85],
    'English': [85, 82, 80]
})

# Melt only the 'Math' and 'Science' columns into long format
long_df = pd.melt(wide_df, id_vars=['Name'], value_vars=['English', 'Science'], var_name='Subject', value_name='Score')

# Print the melted DataFrame
print(long_df)
print("------------")


