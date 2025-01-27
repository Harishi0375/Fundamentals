#FROM CHATGPT
import pandas as pd
# ordinal encoding

# Sample DataFrame with ordinal variable
data = {'Size': ['Small', 'Medium', 'Large', 'Small']}
df = pd.DataFrame(data)

# Define mapping for ordinal encoding
size_mapping = {'Small': 0, 'Medium': 1, 'Large': 2}

# Apply ordinal encoding using map()
df['Size_encoded'] = df['Size'].map(size_mapping)

print(df)
# ---------------------------------

# One-Hot Encoding:

# Sample DataFrame with categorical variable
data = {'Color': ['Red', 'Blue', 'Green', 'Blue', 'Red']}
df = pd.DataFrame(data)

# One-hot encode the 'Color' column
df_encoded = pd.get_dummies(df, columns=['Color'])

print(df_encoded)
# -----------------------------------

# Handling Missing Values:

# Sample DataFrame with missing values
data = {'Color': ['Red', None, 'Green', 'Blue', 'Red']}
df = pd.DataFrame(data)

# Fill missing values with a new category
df['Color'] = df['Color'].fillna('Unknown')

print(df)
# ------------------------------------

# Exploratory Data Analysis (EDA):

# Sample DataFrame with categorical variable
data = {'Color': ['Red', 'Blue', 'Green', 'Blue', 'Red']}
df = pd.DataFrame(data)

# Frequency distribution of 'Color'
print(df['Color'].value_counts())

# Visualize frequency distribution
df['Color'].value_counts().plot(kind='bar')
# --------------------------------------

# Feature Engineering:

# Sample DataFrame with categorical variable
data = {'Color': ['Red', 'Blue', 'Green', 'Blue', 'Red']}
df = pd.DataFrame(data)

# Create new feature based on 'Color'
df['IsRed'] = df['Color'].apply(lambda x: 1 if x == 'Red' else 0)

print(df)
# ---------------------------------------

