firstname = "Zaphod"
lastname = "david"

lastname2 = "davideb"
fullname = firstname + ' ' + lastname
print(fullname)

print(lastname2.count('eb')) #counts number of 'eb'
print(lastname.upper()) #converts to upper
print(lastname.lower()) #converts to lower
print(lastname.lower().capitalize()) #converts to lower and then capitalize
print(lastname.replace('e','a')) #converts all e to a

print(fullname[2])

print(fullname[2:5]) #slicing

#Negative indices refer to the end of a string.
print(fullname[-3])
print(fullname[-5:-2])

sq = 'This string is defined using single quotes.'
print(sq)
print(type(sq))
dq = "This string is defined using double quotes."
print(dq)
print(type(dq))
tq = '''This string is defined using triple quotes.'''
print(tq)
print(type(tq))

#Not only quotes deserve special attention, also the backslash `\`, allowing for multi-line definition of strings as follows.
CCl2F2 = 'Dichloro\
difluoro\
methane'
print(CCl2F2)

# Special characters like quotes or the backslash are considered in Python strings by means of _escape sequences_, e.g., `\'` for a single quote, and `\\` for the backslash(\).
question = 'What\'s the question?'
print(question)
ab = 'a\\b'
print(ab)

s="abcdefgh"
print(s[3:-1])
print(s[3:-1:2])

dct={'a':'b','b':'c'}
print(dct['b'])


#copy string
mylist = ['Hi!',7.3,'Hello!',1.2345e2,1.2345e32,1024,'Guten Tag!',2**64-1]
print(mylist)
### Apply list slicing to extract and print a list with the second, third, and fourth element.
print(mylist[1:4])
### Apply list slicing to extract and print a list with the first, third, and fifth element.
print(mylist[:5:2])
### Create an independent copy of the list and exchange the third element with 'Bonjour!'
newlist = mylist.copy()
newlist[2] = 'Bonjour!'
print(newlist)