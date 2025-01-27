
# Open the input file in read mode
with open("input.txt", "r") as input_file:
    # Read lines from the input file
    lines = input_file.readlines()

# Process the data (convert each line to uppercase)
processed_lines = [line.upper() for line in lines]

# Open the output file in write mode
with open("output.txt", "w") as output_file:
    # Write the processed data to the output file
    output_file.writelines(processed_lines)

print("Data has been processed and written to output.txt.")
