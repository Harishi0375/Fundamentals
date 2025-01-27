import pandas as pd

# Create a sample DataFrame
data = {'group_column': ['A', 'B', 'A', 'B', 'A', 'B'],
        'value': [1, 2, 3, 4, 5, 6]}
df = pd.DataFrame(data)

# Split: Grouping by 'group_column'
grouped = df.groupby('group_column')

# Apply: Summing up values for each group
result = grouped.sum()

# Combine: Resetting index to obtain a DataFrame
combined_result = result.reset_index()

print(combined_result)
