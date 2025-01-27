import mysql.connector

# Connect to the MySQL database
conn = mysql.connector.connect(
    host="localhost",
    user="username",
    password="password",
    database="mydatabase"
)

# Create a cursor object
cursor = conn.cursor()

# Create a table
cursor.execute("CREATE TABLE IF NOT EXISTS students (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT)")

# Insert a record
sql = "INSERT INTO students (name, age) VALUES (%s, %s)"
val = ("Alice", 20)
cursor.execute(sql, val)

# Delete a record
sql = "DELETE FROM students WHERE name = %s"
val = ("Alice",)
cursor.execute(sql, val)

# Add a constraint
cursor.execute("ALTER TABLE students ADD CONSTRAINT uc_name UNIQUE (name)")

# Create another table
cursor.execute("CREATE TABLE IF NOT EXISTS courses (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), student_id INT)")

# Create a view
cursor.execute("CREATE VIEW student_courses AS SELECT s.name AS student_name, c.name AS course_name FROM students s JOIN courses c ON s.id = c.student_id")

# Remove a table
cursor.execute("DROP TABLE IF EXISTS students")

# Remove a view
cursor.execute("DROP VIEW IF EXISTS student_courses")

# Add a new column to the table
cursor.execute("ALTER TABLE students ADD COLUMN gender VARCHAR(10)")

# Drop a column from the table
cursor.execute("ALTER TABLE students DROP COLUMN gender")

# Join tables
cursor.execute("SELECT students.name, courses.name FROM students JOIN courses ON students.id = courses.student_id")

#Remember to commit the changes and close the connection after executing the queries:
# Commit changes
conn.commit()

# Close connection
conn.close()
