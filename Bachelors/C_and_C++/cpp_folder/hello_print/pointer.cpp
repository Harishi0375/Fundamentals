#include <iostream>
using namespace std;

int main()
{   
    int a;
    int b = 5;
    int *ptr;
    ptr = &a;
    cout << ptr << endl;
    *ptr = b;
    cout << *ptr << endl;

    int &ref = a;
    ref = 7;
    cout << &ref << endl;

    return 0;
}