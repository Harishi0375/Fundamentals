import numpy as np

#Using `for` loops, lists can be built as in the following example.
lst1 = [1,'Four',9.0]   #.. list with input values
lst2 = []               #.. initialize output list
for elem in lst1:
    lst2.append(elem+elem)
print('Output list constructed using a for loop:')
print(lst2)


#*List comprehensions* facilitate this type of list construction. 
lst1 = [1,'Four',9.0]   #.. list with input values
lst3 = [elem+elem for elem in lst1]
print('Output list constructed using a list comprehension:')
print(lst3)

#Nested `for` loops are supported in list comprehensions.
lst4 = []               #.. initialize output list
for char1 in 'ABC':
    for char2 in '123':
        lst4.append(char1+char2)
print('Output list constructed using two nested for loops.')
print(lst4)

print('\nOutput list constructed using a list comprehension:')
lst5 = [char1+char2 for char1 in 'ABC' for char2 in '123']
print(lst5)


#sqrt 

lst1 = [1,'Four',9.0]   #.. list with input values
from math import sqrt
### Construction of output list using a for loop and an if-else construct.
lst6 = []               #.. initialize output list
for elem in lst1:
    if type(elem)!=str:
        lst6.append(sqrt(elem))
    else:
        lst6.append('SqrtOf'+elem)
print('Output list constructed using a for loop combined with an if-else statement:')
print(lst6)
### Construction of output list using a list comprehension.
lst7 = [sqrt(elem) if type(elem)!=str else 'SqrtOf'+elem for elem in lst1]
print('\nOutput list constructed using a list comprehension:')
print(lst7)


#In the code cell below, lists are constructed using for loops, possibly combined with conditional statements. Translate the list constructions into list comprehensions. 

lst1 = [4,'Five',8.3,11]    #.. list with input values

### Construction of first output list using a for loop.
lst2 = []                   #.. initialize output list
for elem in lst1:
    lst2.append(elem*3)
print('First output list constructed using a for loop:')
print(lst2)
### Construction of first output list using a list comprehension.
lst3 = []
print('\nFirst output list constructed using a list comprehension:')
print(lst3)

### Construction of second output list using a for loop and nested if-else statements.
lst2 = []                   #.. initialize output list
for elem in lst1:
    if type(elem)==int:
        if elem%2==0:
            lst2.append('even')
        else:
            lst2.append('odd')
    else:
        lst2.append('non-integer')
print('\nSecond output list constructed using a for loop combined with nested if-else statements:')
print(lst2)
### Construction of second output list using a list comprehension.
lst3 = []
print('\nSecond output list constructed using a list comprehension:')
print(lst3)

### Construction of third output list using two nested for loops.
lst2 = []                   #.. initialize output list
for elem1 in lst1[2:]:
    for elem2 in lst1[:-2]:
        lst2.append((elem1,elem2))
print('\nThird output list constructed using two nested for loops:')
print(lst2)
### Construction of third output list using a list comprehension.
lst3 = []
print('\nThird output list constructed using a list comprehension:')
print(lst3)