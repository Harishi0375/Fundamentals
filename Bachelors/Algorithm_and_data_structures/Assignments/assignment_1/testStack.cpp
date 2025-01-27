#include "headerfile.h"
#include <iostream>

using namespace std;

int main() {
    Stack<int> intstack;
    Stack<float, 20> floatstack;

    // Test intstack
    for (int i = 0; i < 11; i++) {
        if (!intstack.push(i)) {
            cout << "push for element: " << i << " failed" << endl;
        }
    }

    // Test floatstack
    for (int i = 0; i < 20; i++) {
        if (!floatstack.push(static_cast<float>(i))) { // Pushing floats
            cout << "push for element: " << i << " failed" << endl;
        }
    }

    // Pop
    float poppedelement;
    for (int i = 0; i < 20; i++) {
        if (floatstack.pop(poppedelement)) {
            cout << poppedelement << " ";
        }
    }
    cout << endl; 

    //return where
    int returndata = floatstack.getNumEntries();
    cout << "where = " << returndata << endl;

    return 0;
}
