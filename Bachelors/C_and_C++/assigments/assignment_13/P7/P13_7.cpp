/*
  CH-230-A
  a13_p7.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <stdexcept>

class OwnException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Default case exception\n";
    }
};

void throwException(int value) {
    switch (value) {
        case 1:
            throw 'a';
        case 2:
            throw 12;
        case 3:
            throw true;
        default:
            throw OwnException();
    }
}

int main() {
    try {
        //char
        throwException(1);
    } catch (char ex) {
        std::cerr << "Caught in main: " << ex << std::endl;
    }

    try {
        //int
        throwException(2);
    } catch (int ex) {
        std::cerr << "main: " << ex << std::endl;
    }

    try {
        //bool 
        throwException(3);
    } catch (bool ex) {
        std::cerr << "in main: " << ex << std::endl;
    }

    try {
        //OwnException
        throwException(4);
    } catch (const OwnException& ex) {
        std::cerr << "in main: " << ex.what();
    }

    return 0;
}
