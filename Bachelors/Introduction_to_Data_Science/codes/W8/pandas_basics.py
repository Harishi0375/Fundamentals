# This tutorial provides an introduction to the Python package Pandas. Follow the instructions below to learn to

# - [ ] construct Pandas Series objects from dictionaries, lists, and arrays,
# - [ ] select elements in a Pandas Series using label-based and integer-based methods,
# - [ ] construct Pandas DataFrame objects from dictionaries, lists, and arrays,
# - [ ] select elements in a Pandas DataFrame using label-based and integer-based methods,
# - [ ] join/merge Pandas DataFrame objects, 
# - [ ] operate on columns in a Pandas DataFrame, and add new columns,
# - [ ] store tabular data from a file in a Pandas DataFrame,
# - [ ] extract and restructure tabular data using Pandas DataFrame objects.

# If you wish to keep track of your progress, you may edit this markdown cell, check a box in the list above after having worked through the respective part of this notebook, and save the file.

# *Short exercises* are embedded in this notebook. *Sample solutions* can be found at the end of the document.

#---------------------------------
#Pandas is a powerful and widely used open-source data manipulation and analysis library for Python. It provides easy-to-use data structures, such as Series and DataFrame, along with a variety of functions for efficiently manipulating large datasets. 


import numpy as np
import matplotlib.pyplot as plt

import pandas as pd #importing pandas

# Pandas Series from Python dictionaries -------------------------------------------

dct1 = { 'a':10, 'b':20 , 'c':30, 'd':40}
print('Dictionary : ',dct1)
print('Keys       : ',dct1.keys())
print('Values     : ',dct1.values())


#When a Python dictionary is turned into a Pandas Series object, the keys are stored in a Pandas Index object.
ser1 = pd.Series(dct1)
print('Series :')
print(ser1)
print('\nIndex  : ',ser1.index)
print('Values : ',ser1.values)



### Pandas Series from Python lists and NumPy arrays

ser2 = pd.Series([10,20,30,40],index=['a','b','c','d'])
print(ser2)

#If a Series is defined without explicit reference to an index, it is derived from the integer positions.

ser3 = pd.Series([10,20,30,40])
print(ser3)
print('\nIndex  : ',ser3.index)


### Selection of elements in a Pandas Series----------------------------------------

#The most intuitive way of selecting individual elements of a Series is through the index. Slicing produces another Series object, with the end element included in the result. The `values` attribute extracts the array of elements.

ser1 = pd.Series( { 'a':10, 'b':20 , 'c':30, 'd':40} )
print("ser1['c'] : ",ser1['c'])
print("ser1['b':'d'].values : ",ser1['b':'d'].values)
print("\nser1['b':'d'] : ")
print(ser1['b':'d'])

#Series elements may also be referenced through their integer position along the index, with the usual logic of Python lists and NumPy arrays (e.g., end elements are omitted).

print("ser1[2] : ",ser1[2])
print("ser1[1:3].values : ",ser1[1:3].values)
print("\nser1[1:3] : ")
print(ser1[1:3])


#In cases where the index is formed from an array of integers, slicing may lead to ambiguities, and then it is saver to reference objects through `.loc` (label-based selection) and `.iloc` (integer-based selection).

ser4 = pd.Series( { 1:10, 2:20, 3:30, 4:40 } )
print("ser4 : ")
print(ser4)
print("\nser4[1:3].values      : ",ser4[1:3].values)
print("ser4.loc[1:3].values  : ",ser4.loc[1:3].values)
print("ser4.iloc[1:3].values : ",ser4.iloc[1:3].values)


#The referencing syntax can be applied to re-assign values, or even define a new element to th Series.
ser5 = pd.Series( { 'a':10, 'b':20 , 'c':30, 'd':40} )
print(ser5)
ser5['c'] = 33
ser5['e'] = 55
print()
print(ser5)

#### Operations on Series objects ------------------------------------------------------------------------

#Operations involving two or more Series objects are naturally aligned with common elements of their index arrays. In the following example, the two Series objects `ser1` and `ser6` share the indices `a`, `c`, `d` but not `b` and `e`. The object `ser7`, defined through an operation involving both `ser1` and `ser6`, contains all index elements from both Series objects but the associated values are defined only for those indices that are shared.

ser1 = pd.Series( { 'a':10, 'b':20 , 'c':30, 'd':40} )
ser6 = pd.Series( { 'a':1, 'c':3 , 'd':4, 'e':5 } ) # 'b' - 'c' cannot happen so prints NaN
ser7 = ser1-ser6
print(ser7)

#Undefined values (`ǸaN`, not-a-number) can be eliminated from a Series by means of the `dropna()` method, with the keyword `inplace` controlling if the Series itself is altered, or a copy is produced (default behavior).

ser7.dropna(inplace=True)
print(ser7)



#panda series exercise -----------------------------------------------------------------------------------------

#According to [Wikipedia (accessed on 2022-07-26)](https://de.wikipedia.org/wiki/Liste_der_Gro%C3%9F-_und_Mittelst%C3%A4dte_in_Deutschland), the resident numbers of Bremen, Dresden, Essen, Stuttgart in the years 1970, 1990, 2010 were as follows.

#  City      | 1970   | 1990   | 2010   | 
# :----------|:------:|:------:|:------:|
#  Bremen    | 592533 | 551219 | 547340 |
#  Dresden   | 502432 | 490571 | 523058 |
#  Essen     | 696419 | 626973 | 574635 |
#  Stuttgart | 634202 | 579988 | 606588 |

# In the cell below, store the three sets of resident numbers for the years 1970, 1990, 2010 in Pandas Series `ser1970`, `ser1990`, `ser2010`, respectively, and complete the code according to the instructions given as comments.

### Construct ser1970 from a dictionary.
ser1970 = pd.Series({'Bremen':592533,'Dresden':502432,'Essen':696419,'Stuttgart':634202})
print('Residents in the year 1970:')
print(ser1970)
### Construct ser1990 using a list of resident numbers and a separate index array.
ser1990 = pd.Series([551219,490571,626973,579988],
                    index=['Bremen','Dresden','Essen','Stuttgart'])
print('\nResidents in the year 1990:')
print(ser1990)
### Copy ser1990 to initialize ser2010, and then re-assign the four values.
ser2010 = ser1990.copy()
ser2010['Bremen'] = 547340
ser2010['Dresden'] = 523058
ser2010['Essen'] = 574635
ser2010['Stuttgart'] = 606588
print('\nResidents in the year 2010:')
print(ser2010)
### Compute the change from 1970 to 1990 and store in serdiff1
serdiff1 = 100*(ser1990-ser1970)/ser1970
print('\nPercentage change in resident number from 1970 to 1990:')
print(serdiff1)
### Compute the percentage change from 1990 to 2010 and store in serdiff2
serdiff2 = 100*(ser2010-ser1990)/ser1990
print('\nPercentage change in resident number from 1990 to 2010:')
print(serdiff2)