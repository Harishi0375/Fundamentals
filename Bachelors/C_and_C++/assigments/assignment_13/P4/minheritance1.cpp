/*
  CH-230-A
  a13_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include<iostream>
using namespace std;

class A
{
    //proper indentation 
    private: //added
        int x;
    public:
        void setX(int i) {x = i;}
        void print() { cout << x; }
};
 
class B:  virtual public A //added virtual keyword
{
public:
  B()  { setX(10); }
};
 
class C:  virtual public A  //added virtual keyword
{
public:
  C()  { setX(20); }
};
 
class D: public B, public C {
    //more than one instance leading to ambiguity. the virtual
    //keyword ensures that theres only one shared instance 
};
 
int main()
{
    D d;
    d.print();
    return 0;
}