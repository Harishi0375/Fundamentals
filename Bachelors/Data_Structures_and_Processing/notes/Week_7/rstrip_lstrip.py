# Suppose your CSV file (example.csv) looks like this:
#    Film    , Genre,  Lead Studio, Audience score %,Profitability,Rotten Tomatoes %,Worldwide Gross , Year

# Notice the leading and trailing whitespace in some column names.

# Now, let's use pandas to read this CSV file, clean up the column names, and then replace "Year" with "Start Year,End Year":

import pandas as pd

# Read the CSV file into a DataFrame
df = pd.read_csv('movies.csv')

# Strip whitespace from column names using rstrip and lstrip
df.columns = df.columns.str.rstrip().str.lstrip()

# Replace 'Year' with 'Start Year,End Year' in the columns
df.columns = df.columns.str.replace('Year', 'Start Year,End Year')

# Print the modified DataFrame
print(df)
