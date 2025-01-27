/*
    CH-231-A
    a1_p5.c
    Nikolay Tsonev
    nTsonev@jacobs-univeristy.de
*/

#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> vstring;

    std::string input = "";

    // same but allows for whitespace and tabs
    while (input != "END") {
        std::getline(std::cin, input);
        if (input != "END")
            vstring.push_back(input);
    }


    // if they exists, it swaps, if not, print appropriate message to user
    if (vstring.size() >= 2 && vstring.size() >= 5) {
        std::string temp = vstring[1];
        vstring[1] = vstring[4];
        vstring[4] = temp;
    } else if (vstring.size() >= 2 && vstring.size() < 5)
        std::cout << "Thith element does not exist\n";
    else if (vstring.size() < 2)
        std::cout << "Thith second does not exist\n";

    vstring[vstring.size()-1] = "???";


    std::vector<std::string>::iterator itor;
    for (itor = vstring.begin(); itor < vstring.end(); itor++) {
        if (itor != vstring.end() - 1) {
            std::cout << *itor << ", ";
        } else {
            std::cout << *itor << "\n";
        }
    }
    
    for (itor = vstring.begin(); itor < vstring.end(); itor++) {
        if (itor != vstring.end() - 1) {
            std::cout << *itor << "; ";
        } else {
            std::cout << *itor << "\n";
        }
    }

    // same but the point begins at the end and decrement to print in reverse
    for (itor = vstring.end(); itor != vstring.begin(); itor--) {
        if (itor != vstring.begin()+1) {
            std::cout << *itor << " ";
        } else {
            std::cout << *itor << "\n";
        }
    }
    


    return 0;
}