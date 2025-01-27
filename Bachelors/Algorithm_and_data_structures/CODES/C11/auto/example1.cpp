#include <iostream>
#include <typeinfo>

//auto vs decltype

using namespace std;

int main() {
    // Example using auto
    auto x = 5; // x will be of type int
    auto y = 3.5; // y will be of type double
    auto z = "hello"; // z will be of type const char*

    cout << "Using auto:" << endl;
    cout << "x: " << x << " (type: " << typeid(x).name() << ")" << endl;
    cout << "y: " << y << " (type: " << typeid(y).name() << ")" << endl;
    cout << "z: " << z << " (type: " << typeid(z).name() << ")" << endl;

    // Example using decltype
    int a = 10;
    double b = 3.14;
    decltype(a) c = a; // c will be of type int
    decltype(a + b) d = a + b; // d will be of type double

    cout << "\nUsing decltype:" << endl;
    cout << "c: " << c << " (type: " << typeid(c).name() << ")" << endl;
    cout << "d: " << d << " (type: " << typeid(d).name() << ")" << endl;

    return 0;
}
