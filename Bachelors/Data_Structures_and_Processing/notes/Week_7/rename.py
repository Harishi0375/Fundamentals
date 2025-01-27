# The rename() function in pandas is used to rename index 
# or column labels. Here's an example demonstrating how 
# to use the rename() function to rename columns in a DataFrame:

import pandas as pd

# Sample DataFrame
data = {'A': [1, 2, 3],
        'B': [4, 5, 6],
        'C': [7, 8, 9]}
df = pd.DataFrame(data)

# Rename columns using the rename() function
df = df.rename(columns={'A': 'X', 'B': 'Y', 'C': 'Z'})

# Print the DataFrame with renamed columns
# print(df)
# -----------------------------------------

# Rename columns using the rename() function with mapper=
df = df.rename(mapper={'A': 'X', 'B': 'Y', 'C': 'Z'}, axis=1)
# axis = 1 : row
# axis = 0 : col

# Print the DataFrame with renamed columns
print(df)
