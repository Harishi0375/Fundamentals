#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("position_example.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    // Write some data to the file
    outFile << "Hello, World!\n";

    // Get the current position of the put pointer
    std::streampos putPosition = outFile.tellp();
    std::cout << "Current put pointer position: " << putPosition << std::endl;

    // Move the put pointer to the beginning of the file
    outFile.seekp(0, std::ios::beg);

    // Write more data at the beginning of the file
    outFile << "New data at the beginning\n";

    // Get the new position of the put pointer
    putPosition = outFile.tellp();
    std::cout << "New put pointer position: " << putPosition << std::endl;

    // Close the file
    outFile.close();

    // Open the file for reading
    std::ifstream inFile("position_example.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Move the get pointer to the end of the file
    inFile.seekg(0, std::ios::end);

    // Get the current position of the get pointer
    std::streampos getPosition = inFile.tellg();
    std::cout << "Current get pointer position: " << getPosition << std::endl;

    // Close the file
    inFile.close();

    return 0;
}
