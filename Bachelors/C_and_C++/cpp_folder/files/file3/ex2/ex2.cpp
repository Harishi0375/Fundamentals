//moving within a stream 

#include <iostream>
#include <fstream>

int main() {
    // Open a file for reading and writing
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::trunc);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Write some data to the file
    file << "Hello, World!" << std::endl;

    // Move the get pointer to the beginning of the file
    file.seekg(0, std::ios::beg);

    // Read and print the content from the current position to the end of the file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << "Read: " << line << std::endl;
    }

    // Move the put pointer to the end of the file
    file.seekp(0, std::ios::end);

    // Write more data to the end of the file
    file << "Appending more content!" << std::endl;

    // Move the get pointer back to the beginning of the file
    file.seekg(0, std::ios::beg);

    // Read and print the updated content
    std::cout << "\nUpdated content:\n";
    while (std::getline(file, line)) {
        std::cout << "Read: " << line << std::endl;
    }

    // Close the file
    file.close();

    return 0;
}
