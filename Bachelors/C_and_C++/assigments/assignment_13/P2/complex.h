/*
  CH-230-A
  a13_p2.h
  Harishi Velavan
  hvelavan@jacobs-university.de
*/


#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <fstream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double realPart, double imagPart);
    Complex(const Complex& other);
    ~Complex();

    double getReal() const;
    double getImag() const;

    void setReal(double realPart);
    void setImag(double imagPart);

    Complex conjugate() const;
    Complex add(const Complex& other) const;
    Complex subtract(const Complex& other) const;
    Complex multiply(const Complex& other) const;

    void print() const;

    // Overloaded operators
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex& operator=(const Complex& other);
    
    friend std::istream& operator>>(std::istream& is, Complex& complex);
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};

#endif
