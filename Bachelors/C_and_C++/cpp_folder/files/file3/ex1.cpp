// std::ios::in: Open for input operations (read).

// std::ios::out: Open for output operations (write).

// std::ios::app: Append mode. All output operations are performed at the end of the file.

// std::ios::ate: Open and move to the end of the file.

// std::ios::trunc: If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

// std::ios::binary: Open in binary mode.

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open an input file stream for reading
    std::ifstream inFile("input.txt", std::ios::in | std::ios::binary);

    // Check if the input file is open
    if (!inFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Open an output file stream for writing in append mode
    std::ofstream outFile("output.txt", std::ios::out | std::ios::app | std::ios::binary);

    // Check if the output file is open
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        inFile.close();  // Close the input file before exiting
        return 1;
    }

    std::string line;

    // Read lines from the input file
    while (std::getline(inFile, line)) {
        // Process the line (e.g., modify the content)
        // For simplicity, let's just add "Processed: " to each line
        line = "Processed: " + line;

        // Write the modified line to the output file
        outFile << line << std::endl;
    }

    // Close the file streams
    inFile.close();
    outFile.close();

    std::cout << "File contents processed and written to output.txt." << std::endl;

    return 0;
}
