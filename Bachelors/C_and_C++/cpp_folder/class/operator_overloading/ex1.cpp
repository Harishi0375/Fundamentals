#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r,double i) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    // Display function to print the values
    void display() {
        std::cout << "Real: " << real << " Imaginary: " << imag << std::endl;
    }
};

int main() {
    // Creating two Complex objects
    Complex c1, c2;

    Complex c3(3,4);

    // Setting values for c1 and c2
    c1.display(); // Outputs: Real: 0 Imaginary: 0
    c2.display(); // Outputs: Real: 0 Imaginary: 0

    // Adding c1 and c2 using the overloaded + operator
    Complex result = c1 + c2 + c3;
    result.display(); // Outputs: Real: 0 Imaginary: 0

    return 0;
}
