# #One-Hot Encoding: One-Hot Encoding is a popular
#  method for converting categorical variables into
#  numerical format. In this technique, each category
# is represented as a binary vector where only one 
# element is "hot" (1) while the rest are "cold" (0).
# This method creates new binary columns for each 
# category, effectively encoding the categorical data.

import numpy as np

def get_one_hot_encoding(feature):
    categories, idxs = np.unique(feature, return_inverse=True) 
    ohe_matrix = np.zeros((len(feature), len(categories))) 
    ohe_matrix[np.arange(len(feature)), idxs] = 1 
    return ohe_matrix 

print(get_one_hot_encoding(['a', 'b', 'c', 'a', 'b']))

# >>> array([[1., 0., 0.], 
#            [0., 1., 0.], 
#            [0., 0., 1.], 
#            [1., 0., 0.], 
#            [0., 1., 0.]]) 

# Advantages:

# Simple and straightforward to implement.
# Preserves the information of each category without imposing any ordinal relationship.
# Disadvantages:

# Can lead to high-dimensional data when dealing with a large number of categories.

# ---------------------------------------------------
# Label Encoding: Label Encoding is another method 
# for converting categorical variables into numerical
#    format by assigning a unique integer to each category. 
# Each category is mapped to a specific integer value, 
# thereby transforming the categorical data into ordinal form.

def get_label_encoding(feature):
    _, idxs = np.unique(feature, return_inverse=True) 
    return idxs 

get_label_encoding(['a', 'b', 'c', 'a', 'b']) 

# >>> array([0, 1, 2, 0, 1])

# Advantages:

# Efficient for ordinal categorical variables with inherent order.
# Reduces dimensionality compared to One-Hot Encoding.
# Can improve computational efficiency in certain algorithms.
# Disadvantages:

# Imposes an arbitrary order on categorical variables, which may not reflect their true relationships. For example, we can't say that Action genre is larger than Animation. Using this Label Encoding we will set such relationship. 
# May mislead algorithms into interpreting ordinal values as meaningful distances. 
# Not suitable for categorical variables without a natural order.

# ------------------------------------------
    
# Target Encoding (Mean Encoding): Target Encoding, also 
# known as Mean Encoding, involves replacing each category
# with the mean of the target variable for that category. 
# This method leverages the target variable to encode 
# categorical data based on their relationship with the target variable.

def get_target_encoding(feature, target):
    _, idxs, inverse_idxs = np.unique(feature, return_index=True, return_inverse=True) 
    target_encodings = np.zeros(len(feature)) 
    for idx in idxs: 
        mask = inverse_idxs == idx 
        target_encodings[mask] = target[mask].mean() 

    return target_encodings 

target = np.array([1, 4, 2, 2, 3]) 
get_target_encoding(['a', 'b', 'c', 'a', 'b'], target) 

# >>> array([1.5, 3.5, 2. , 1.5, 3.5])
# Advantages:

# Captures the relationship between categories and the target variable.
# Reduces dimensionality compared to One-Hot Encoding.
# Can improve predictive performance in classification and regression tasks.
# Disadvantages:

# Prone to overfitting when there are rare categories in the data.
# May introduce bias if the target variable is imbalanced.
# Vulnerable to leakage of target variable if not implemented carefully.