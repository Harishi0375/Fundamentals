week2 = []
with open("week2.txt", "r") as infile:
    counter = 1
    for k in infile.readlines():
        week2.append("line " + str(counter) + ": " + k)
        counter = counter + 1

with open("week2-new.txt", "w") as outfile:
    for k in week2:
        outfile.write(k)