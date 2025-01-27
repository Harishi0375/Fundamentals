import numpy as np

# Load the CSV file using NumPy
data = np.genfromtxt('your_file.csv', delimiter=',', dtype=str)

# Find the index of the 'Year' column in the header row
header = data[0]
year_index = np.where(header == 'Year')[0][0]

# Replace 'Year' with 'Start Year,End Year' in the header
header[year_index] = 'Start Year,End Year'

# Print the modified header
print(header)

# Print the rest of the rows
for row in data[1:]:
    print(row)
