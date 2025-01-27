/*
  CH-230-A
  a13_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <string>

void copyFile(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);
    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return;
    }

    size_t dotPosition = inputFileName.find_last_of(".");
    std::string fileExtension = (dotPosition != std::string::npos) ? inputFileName.substr(dotPosition) : "";

    std::string outputFileName = inputFileName.substr(0, dotPosition) + "_copy" + fileExtension;
    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully. New file name: " << outputFileName << std::endl;
}

int main() {
    std::cout << "Enter the name of the file: ";
    std::string inputFileName;
    std::cin >> inputFileName;

    copyFile(inputFileName);

    return 0;
}



