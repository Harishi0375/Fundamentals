/*
  CH-230-A
  a10_p8.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "Complex.h"
#include <iostream>

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

Complex::~Complex() {}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

void Complex::setReal(double realPart) {
    real = realPart;
}

void Complex::setImag(double imagPart) {
    imag = imagPart;
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

Complex Complex::add(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::subtract(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::multiply(const Complex& other) const {
    double resultReal = real * other.real - imag * other.imag;
    double resultImag = imag * other.real + real * other.imag;
    return Complex(resultReal, resultImag);
}

void Complex::print() const {
    std::cout << real;
    if (imag >= 0) std::cout << " + " << imag << "i";
    else std::cout << " - " << -imag << "i";
    std::cout << std::endl;
}
