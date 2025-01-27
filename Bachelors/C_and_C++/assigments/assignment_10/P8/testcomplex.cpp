/*
  CH-230-A
  a10_p8.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Complex.h"

int main() {
    Complex c1, c2;

    std::cout << "Enter real and imaginary parts for Complex number 1: ";
    double real1, imag1;
    std::cin >> real1 >> imag1;
    c1.setReal(real1);
    c1.setImag(imag1);

    std::cout << "Enter real and imaginary parts for Complex number 2: ";
    double real2, imag2;
    std::cin >> real2 >> imag2;
    c2.setReal(real2);
    c2.setImag(imag2);

    Complex conjugateC1 = c1.conjugate();
    std::cout << "Conjugate of Complex number 1: ";
    conjugateC1.print();

    Complex sum = c1.add(c2);
    std::cout << "Sum of Complex numbers 1 and 2: ";
    sum.print();

    Complex difference = c2.subtract(c1);
    std::cout << "Difference of Complex numbers 2 and 1: ";
    difference.print();

    Complex product = c1.multiply(c2);
    std::cout << "Product of Complex numbers 1 and 2: ";
    product.print();

    return 0;
}
