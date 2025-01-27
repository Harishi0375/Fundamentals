#include "headerfile.h"
#include <iostream>

using namespace std;

int main() {
    doublylinkedlist<int> list;

    for (int i = 1; i <= 5; ++i) {
        list.insertAtFront(i);
    }

    cout << "List elements: ";
    while (list.getSize() > 0) {
        cout << list.removeFront() << " ";
    }
    cout <<  ::endl;

    return 0;
}
