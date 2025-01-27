infile = open("week2.txt", "r")
counter = 1
for line in infile.readlines():
    print("line " + str(counter) + ": " + line)
    counter = counter + 1
infile.close()

