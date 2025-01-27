/*
    CH-231-A
    a1_p1.c
    Nikolay Tsonev
    nTsonev@jacobs-univeristy.de
*/

#include <iostream>

class Complex {
public:
    Complex(int real, int img) : real(real), img(img) {}
    // used for the comparrison function in the array search function
    friend bool operator==(const Complex& c1, const Complex& c2) {
        return (c2.real == c1.real && c2.img == c1.img);
    }

private:
    int real;
    int img;
};

template <typename T>
int array_search(T array[], int n, T find) {
    for (int i = 0; i < n; i++) {
        if (array[i] == find)
            return i;
    }
    return -1;
}


int main() {
    // creating array
    Complex array[5] = {
        Complex(1, 2),
        Complex(3, 4),
        Complex(5, 6),
        Complex(7, 8),
        Complex(9, 10)
    };

    int intArray[5] = {1, 2, 3, 4, 5};

    std::cout << array_search<int>(intArray, 5, 2) << std::endl;
    std::cout << array_search<int>(intArray, 5, 6) << std::endl;    

    Complex find(5, 6);
    Complex fake(11, 12);

    // should print 2 and -1
    std::cout << array_search<Complex>(array, 5, find) << std::endl;
    std::cout << array_search<Complex>(array, 5, fake) << std::endl;

    return 0;
}