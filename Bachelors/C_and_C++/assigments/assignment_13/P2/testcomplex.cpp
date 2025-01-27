/*
  CH-230-A
  a13_p2.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

// testComplex.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "Complex.h"

int main() {
    std::ifstream inFile1("in1.txt");
    std::ifstream inFile2("in2.txt");
    std::ofstream outFile("output.txt");

    Complex c1, c2;

    // Read complex numbers from files
    inFile1 >> c1;
    inFile2 >> c2;

    c1.print();
    c2.print();

    // Compute and print results
    outFile << "Sum: " << c1 + c2 << std::endl;
    outFile << "Difference: " << c1 - c2 << std::endl;
    outFile << "Product: " << c1 * c2 << std::endl;

    std::cout << "Results have been written to output.txt" << std::endl;
    // std::cout << "content in output.txt file: " << std::endl;



    // std::string line;
    // while (std::getline(outFile, line)) 
    // {
    //     std::cout << line << std::endl;
    // }

    inFile1.close();
    inFile2.close();
    outFile.close();

    return 0;
}
