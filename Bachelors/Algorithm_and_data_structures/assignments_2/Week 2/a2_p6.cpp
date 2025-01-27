//
// Created by Nikolay Tsonev on 14/02/2024.
//

#include <iostream>
#include <fstream>
#include <map>

int main() {

    std::map<std::string, std::string> mappies;

    std::ifstream files("data.txt");

    // read from the file which contains a name followed by an int and add it to the map
    std::string name;
    std::string surname;
    std::string bday;

    while (files >> name >> surname>>  bday) {
        mappies[name+" "+surname] = bday;
    }

    std::map<std::string, std::string>::iterator mitor;
    for(mitor = mappies.begin(); mitor != mappies.end(); mitor++)
        std::cout << mitor->first << " : " << mitor->second << std::endl;


    return 0;
}