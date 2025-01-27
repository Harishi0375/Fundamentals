import pandas as pd

# Sample DataFrame
data = {'Name': ['Alice', 'Bob', 'Charlie'],
        'Math': [90, 85, 92],
        'Science': [88, 90, 95]}
df = pd.DataFrame(data)
print(df)

# Custom function to calculate average score
def calculate_average(row):
    return (row['Math'] + row['Science']) / 2

# Apply the custom function to each row to calculate average score
df['Average Score'] = df.apply(calculate_average, axis=1)

# Print the DataFrame with the average score
print(df)


df.votes = df.votes.str.replace(',', '')
df.rating = df.rating.astype(float)
df[['votes', 'run_time']] = df[['votes', 'run_time']].astype('Int64')