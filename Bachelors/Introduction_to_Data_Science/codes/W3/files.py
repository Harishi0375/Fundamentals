fin = open('cities.txt','r')
content = fin.read()
print(content)
fin.close()



#Applying the function `split()` with the newline character `\n` as its argument gives a list of strings, each corresponding to one line from the data file. This is equivalent to using the function `splitlines()`.

lines = content.split('\n')
#lines = content.splitlines()
print(lines,type(lines))

#Each line can now be processed further to extract information.
BremenRecord = lines[1].split(',')
BremenArea = float(BremenRecord[1])
print('Bremen area [km2]: {}'.format(BremenArea))


#read content from file and count 
fin = open('gdp-per-capita-in-us-dollar-world-bank.csv','r')
content = fin.read()
fin.close()
country = 'Australia'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))
country = 'Bhutan'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))
country = 'Canada'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))
country = 'Denmark'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))
country = 'Ecuador'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))
country = 'Fiji'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))
country = 'Gambia'
print("Number of occurences of the string \'{}\' : {}".format(country,content.count(country)))