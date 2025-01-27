/*
  CH-230-A
  a11_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "Vector.h"

using namespace std;

Vector::Vector() : size(0), ptr(nullptr)
{
    // default 
}


Vector::Vector(int nsize, const double *nptr) : size(nsize)
{
    ptr = new double[size];    
}

Vector::Vector(int nsize) //needed for norm 
{
    size = nsize;
    ptr = new double[size];
}

Vector::Vector(const Vector &other)
{
    size = other.size;
    ptr = new double(size);
    for (int i = 0; i < size; i++)
    {
        ptr[i] = other.ptr[i];
    }
}

Vector::~Vector()
{
    delete[] ptr;
}

void Vector::setSize(int nsize)
{
    size = nsize;
    ptr = new double[size];
}

int Vector::getSize() const
{
    return size;
}

void Vector::setPtr(double *nptr)
{
    ptr = nptr;
}

double *Vector::getPtr() const
{
    return ptr;
}

double Vector::norm() const
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + (ptr[i]*ptr[i]);
    }
    return sqrt(sum);
}

double Vector::scalarProduct(const Vector& other) const {
    double result = 0.0;
    for (int i = 0; i < size; ++i) {
        result = result + ptr[i] * other.ptr[i];
    }
    return result;
}

Vector Vector::add(const Vector& other) const {
    Vector result(size, ptr);
    for (int i = 0; i < size; ++i) {
        result.ptr[i] = result.ptr[i] + other.ptr[i];
    }
    return result;
}

Vector Vector::subtract(const Vector& other) const {
    Vector result(size, ptr);
    for (int i = 0; i < size; ++i) {
        result.ptr[i] = result.ptr[i] - other.ptr[i];
    }
    return result;
}

void Vector::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}
