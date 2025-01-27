import pandas as pd

# Nested dictionary representing information about students
students = {
    'Alice': {'Math': 90, 'Science': 88},
    'Bob': {'Math': 85, 'Science': 90},
    'Charlie': {'Math': 92, 'Science': 95}
}

# Accessing values in the nested dictionary
print(students['Alice'])  # Output: {'Math': 90, 'Science': 88}
print(students['Bob']['Science'])  # Output: 90

# Convert the nested dictionary to a DataFrame
df = pd.DataFrame.from_dict(students, orient='index')

df = df.rename(columns={'Science':'Physics'})
print(df)

#random example
df = df.replace({"male" : 1,"female" : 0})