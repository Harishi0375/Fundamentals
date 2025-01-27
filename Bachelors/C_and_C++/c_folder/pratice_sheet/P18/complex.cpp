#include <iostream>

#include "complex.h"

using namespace std;

void Complex::print() const{
    if (imag){
        cout << noshowpos << real << showpos << imag << "i" << endl;
    }
    else{
        cout << noshowpos << real << endl;
    }
}


ostream& operator<<(ostream &out,const Complex &obj)
{
    if(obj.imag)
    {
        out << noshowpos << obj.real << showpos << obj.imag << "i" << endl;
    } 
    else
    {
        out << noshowpos << obj.real << endl;
    }
    return out;
}
