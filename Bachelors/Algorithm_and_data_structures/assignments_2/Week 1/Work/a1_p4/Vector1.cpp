/*
    CH-231-A
    a1_p4.c
    Nikolay Tsonev
    nTsonev@jacobs-univeristy.de
*/

#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> vstring;

    std::string input = "";

    // looping forevr until user inputs END and add all of the input that ! END
    while (input != "END") {
        std::cin >> input;
        if (input != "END")
            vstring.push_back(input);
    }

    // print sperated by a space
    for (std::string s : vstring)
        std::cout << s << " ";
    std::cout << std::endl;

    // print seperated by comma apart fromt the last one
    std::vector<std::string>::iterator itor;
    for (itor = vstring.begin(); itor < vstring.end(); itor++) {
        if (itor != vstring.end() - 1) {
            std::cout << *itor << ", ";
        } else {
            std::cout << *itor << "\n";
        }
    }

    return 0;
}