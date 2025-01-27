import pandas as pd
# One-Hot Encoding:

# Sample DataFrame with categorical variable
data = {'Color': ['Red', 'Blue', 'Green', 'Blue', 'Red']}
df = pd.DataFrame(data)

# One-hot encode the 'Color' column using pandas
df_encoded = pd.get_dummies(df, columns=['Color'])

print("One-Hot Encoding:")
print(df_encoded)
# -------------------------------------------------------

# Label Encoding:
from sklearn.preprocessing import LabelEncoder

# Sample DataFrame with ordinal variable
data = {'Size': ['Small', 'Medium', 'Large', 'Small']}
df = pd.DataFrame(data)

# Label encode the 'Size' column using scikit-learn
label_encoder = LabelEncoder()
df['Size_encoded'] = label_encoder.fit_transform(df['Size'])

print("Label Encoding:")
print(df)
# ---------------------------------------------
# Target Encoding (Mean Encoding):
import category_encoders as ce

# Sample DataFrame with categorical variable and target variable
data = {'Color': ['Red', 'Blue', 'Green', 'Blue', 'Red'],
        'Target': [1, 0, 1, 0, 1]}
df = pd.DataFrame(data)

# Target encode the 'Color' column using category_encoders
target_encoder = ce.TargetEncoder(cols=['Color'])
df_encoded = target_encoder.fit_transform(df['Color'], df['Target'])

print("Target Encoding (Mean Encoding):")
print(df_encoded)

