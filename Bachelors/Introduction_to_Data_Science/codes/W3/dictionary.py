# Creating a dictionary
student = {
    'name': 'John Doe',
    'age': 20,
    'grade': 'A',
    'courses': ['Math', 'English', 'Science'],
    'contact': {
        'email': 'john@example.com',
        'phone': '123-456-7890'
    }
}

# Accessing dictionary elements
print("Student Name:", student['name'])
print("Student Age:", student['age'])
print("Courses:", student['courses'])
print("Courses:", student['courses'][1])

print("Email:", student['contact']['email'])

# Modifying a value
student['age'] = 21

# Adding a new key-value pair
student['gender'] = 'Male'

# Displaying the modified dictionary
print("\nModified Dictionary:")
print(student)





DictOfFruits = {'Apples':19,'Bananas':13,'Oranges':17,'Pears':11}
print('Dictionary : ',DictOfFruits)

print('Keys       : ',DictOfFruits.keys())
print('Values     : ',DictOfFruits.values())
print('Items      : ',DictOfFruits.items())
print(DictOfFruits['Oranges'])


