#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
 

 int main()
 {
    std::map<std::string,std::string> nameBirthdayMap;

    std::ifstream inFile("data.txt");
    std::string line;
    while (std::getline(inFile,line))
    {
        std::istringstream iss(line);
        std::string firstName, lastName, birthday;
        iss >> firstName >> lastName >> birthday;
        std::string fullName = firstName + " " + lastName;
        nameBirthdayMap[fullName] = birthday;
    }

    inFile.close();

    std::string queryName;
    std::cout << "Enter a name to query: ";
    std::getline(std::cin, queryName);

    if (nameBirthdayMap.find(queryName) != nameBirthdayMap.end()) {
        std::cout << "Birthday date for " << queryName << ": " << nameBirthdayMap[queryName] << std::endl;
    } else {
        std::cout << "Name not found!" << std::endl;
    }

    return 0;
    
 }