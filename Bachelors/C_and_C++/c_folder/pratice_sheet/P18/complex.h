#include <ostream>
#ifndef COMPLEX_H
#define COMPLE_H

using namespace std;
class Complex {
    private:
        float real; // real part
        float imag; // imaginary part
    public:
        Complex();
        Complex(float, float = 0);
        double magnitude() const;
        void print() const;

        friend ostream& operator<<(ostream &out,const Complex &obj);

        
};

#endif