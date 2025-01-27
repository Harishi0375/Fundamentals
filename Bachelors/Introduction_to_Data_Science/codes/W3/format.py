#Numerical values can be incorporated in Python strings using the `format()` function. 
a = 3.14159265
str1 = "The number pi is {}.".format(a)
print(str1)

#first 4 digits after decimal
a = 3.14159265359
str2 = 'The number pi is {:.4f}.'.format(a)
print(str2)

#multiple variables
a = 3.14159265359
b = 2.71828182846
str3 = 'The numbers pi and e are {pi:.4f} and {e:.4f}, respectively.'.format(pi=a,e=b)
print(str3)

#or
a = 3.14159265359
b = 2.71828182846
str3 = 'The numbers pi and e are {:.4f} and {:.4f}, respectively.'.format(a,b)
print(str3)

i1 = 3
print('i1={}    : float(i1)={}'.format(i1,float(i1)))
f2 = 4.3
print('f2={}  : int(f2)={}'.format(f2,int(f2)))
f3 = -4.3
print('f3={} : int(f3)={}'.format(f3,int(f3)))