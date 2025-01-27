/*
  CH-230-A
  a11_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Box.h"

using namespace std;

int main(int argc, char** argv) {
    int n;
    double height, width, depth;
    cout << "Enter value for n: ";
    cin >> n;
    Box* arr = new Box[n * 2];

    for (int i = 0; i < n; i++) {
        cout << "Enter height, width, and depth for box " << i + 1 << ": " << endl;
        cin >> height >> width >> depth;

        arr[i] = Box(height, width, depth);
    }

    for (int i = n; i < 2 * n; i++) {
        arr[i] = arr[i - n]; // Copy constructor
    }

    for (int i = 0; i < 2 * n; ++i) {
        arr[i].print();
    }

    delete[] arr;

    return 0;
}
