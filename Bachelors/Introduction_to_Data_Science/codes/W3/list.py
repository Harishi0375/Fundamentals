#Python lists are collections of objects of possibly different types. Lists are enclosed in square brackets `[...]`.

lst1 = [2,'three',4,5.6]
lst2 = ['seven',8.9,10]
lst3 = lst1 + lst2
print(lst3)

m = 2
n = 5

print('Number of elements in lst1: {}'.format(len(lst1)))
print('Number of elements in lst2: {}'.format(len(lst2)))
print('Number of elements in lst3: {}'.format(len(lst3)))
print('Partial  list lst3[{}:{}] :'.format(m,n),lst3[m:n])