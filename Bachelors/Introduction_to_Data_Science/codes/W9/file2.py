## GroupBy mechanism-----------------------------------------------------------------------------

# The summary statistics computed from the restructured life expectancy DataFrame `leb` are examples of aggregates. If only such results of aggregation operations or related functions are sought, one may invoke the Pandas GroupBy mechanism with the original DataFrame `leb_full`, thus effectively skipping the potentially resource-consuming restructuring step.

# The GroupBy mechanism is usually understood as a sequence of three operations.
# 1. *Split* a DataFrame according to the values of a specific key to produced groups.
# 2. *Apply* a function (aggregation, transformation, filtering, ...) within each group. 
# 3. *Combine* the results into an array.
from sys import displayhook
import numpy as np
import matplotlib.pyplot as plt

import pandas as pd

# Create a DataFrame
df = pd.DataFrame({
    'Category': ['A', 'B', 'A', 'B', 'A', 'B'],
    'Value': [10, 20, 15, 25, 12, 22]
})

# Group by 'Category'
grouped = df.groupby('Category')
print(grouped)


# Calculate the mean for each group
mean_values = grouped.mean()
print(mean_values)

# Subtract the mean of each group from the values
transformed_values = df['Value'] - grouped.transform('mean')
print(transformed_values)

# Keep only groups where the mean is greater than a threshold
filtered_groups = grouped.filter(lambda x: x['Value'].mean() > 15)
print(filtered_groups)

# Iterate over groups
for name, group in grouped:
    print(name)
    print(group)

# Define a custom aggregation function
def custom_agg(x):
    return x.max() - x.min()

# Apply the custom aggregation function to each group
custom_aggregation = grouped.agg(custom_agg)

# Group by multiple columns
multi_grouped = df.groupby(['Category', 'Subcategory'])

# Apply multiple aggregation functions
result = multi_grouped.agg({
    'Value': 'sum',
    'Quantity': 'mean'
})

# Create a DataFrame with a time series
df_time = pd.DataFrame({
    'Date': pd.date_range('2023-01-01', periods=6),
    'Value': [10, 20, 15, 25, 12, 22]
})

# Group by year and month
grouped_time = df_time.groupby(df_time['Date'].dt.to_period("M"))




