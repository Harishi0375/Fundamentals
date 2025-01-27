/*
  CH-230-A
  a11_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#ifndef __VECTOR_H
#define __VECTOR_H

#include <iostream>
#include <cmath>

class Vector
{
    private:
        int size;
        double *ptr;
    public:
        void setSize(int nsize);
        void setPtr(double *nptr);

        int getSize() const;
        double *getPtr() const;

        double norm() const;
        Vector add(const Vector& other) const;
        double scalarProduct(const Vector& other) const;
        Vector subtract(const Vector& other) const;
        
        Vector(); //default
        Vector(int);
        Vector(int size,const double *ptr); 
        Vector(const Vector&); //copy
        ~Vector(); //destructor

        void print() const;
};

#endif