#include <iostream>
#include <fstream>

int main() {
    // Writing to a file
    std::ofstream outFile("output.txt");
    outFile << "Hello, file!" << std::endl;
    outFile.close();

    // Reading from a file
    std::ifstream inFile("output.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << "File content: " << line << std::endl;
    }
    inFile.close();

    return 0;
}
