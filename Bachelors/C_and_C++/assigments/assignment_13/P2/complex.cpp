/*
  CH-230-A
  a13_p2.cpp
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
    return Complex(this->real + other.real, this->imag + other.imag);
}

Complex Complex::subtract(const Complex& other) const {
    return Complex(this->real - other.real, this->imag - other.imag);
}

Complex Complex::multiply(const Complex& other) const {
    double resultReal = this->real * other.real - this->imag * other.imag;
    double resultImag = this->imag * other.real + this->real * other.imag;
    return Complex(resultReal, resultImag);
}

void Complex::print() const {
    std::cout << real;
    if (imag >= 0) std::cout << " + " << imag << "i";
    else std::cout << " - " << -imag << "i";
    std::cout << std::endl;
}

// operators use the already written functions 
Complex Complex::operator+(const Complex& other) const {
    return add(other);
}

Complex Complex::operator-(const Complex& other) const {
    return subtract(other);
}

Complex Complex::operator*(const Complex& other) const {
    return multiply(other);
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
    double realPart, imagPart;
    is >> realPart >> imagPart; //goes line by line 
    complex.setReal(realPart);
    complex.setImag(imagPart);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.getReal();
    if (complex.getImag() >= 0) os << " + " << complex.getImag() << "i";
    else os << " - " << -complex.getImag() << "i";
    return os;
}