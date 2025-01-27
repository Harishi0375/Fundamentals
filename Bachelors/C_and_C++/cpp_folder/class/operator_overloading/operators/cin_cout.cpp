#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    // Overloading << for output
    friend std::ostream& operator<<(std::ostream& out, const Complex& obj) {
        out << "Real: " << obj.real << " Imaginary: " << obj.imag;
        return out;
    }

    // Overloading >> for input
    friend std::istream& operator>>(std::istream& in, Complex& obj) {
        std::cout << "Enter real part: ";
        in >> obj.real;

        std::cout << "Enter imaginary part: ";
        in >> obj.imag;

        return in;
    }
};

int main() {
    Complex c1;

    // Using overloaded >> for input
    std::cin >> c1;

    // Using overloaded << for output
    std::cout << "You entered: " << c1 << std::endl;

    return 0;
}
