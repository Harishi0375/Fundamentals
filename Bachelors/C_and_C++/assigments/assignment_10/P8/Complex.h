/*
  CH-230-A
  a10_p8.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#ifndef COMPLEX_H
#define COMPLEX_H

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
};

#endif
