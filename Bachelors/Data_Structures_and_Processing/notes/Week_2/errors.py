x = (1,2,3,"4")
# x[2] = 100 ##error this not possible in tuple 

y = 1+2j
print(y)


try:
    1/0
    print("Line 2 from try block")
except:
    print("Line 1 from except block.")
    print("Line 2 from except block.")
else:
    print("Line 1 from else block")
    print("Line 2 from else block")
finally:
    print("Line 1 from finally block")
    print("Line 2 from finally block")

