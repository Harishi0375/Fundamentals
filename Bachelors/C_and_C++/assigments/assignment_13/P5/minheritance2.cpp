/*
  CH-230-A
  a13_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include<iostream>
using namespace std;
 
class A
{
    private:
        int x;
    public:
        A(int i) { x = i; } //setter
        void print() { cout << x; }
};
 
//indentation for better reading 
class B: virtual public A
{
public:
  B() : A(10) {  }
};
 
class C:  virtual public A 
{
public:
  C() : A(10) {  }
};
 
class D: public B, public C {
public: //used public so that it can be accessed in the main function 

    D() : A(10) {} //This ensures that the A part of the D class is
                // properly initialized, resolving the compilation error.
};
 
int main()
{
    D d;
    d.print();
    return 0;
}