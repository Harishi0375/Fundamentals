/*
  CH-230-A
  a9_p7.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>

using namespace std;

void swapping(int &a, int &b) // swap ints
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapping(float &a, float &b)// swap floats
{
    float temp;
    temp = a;
    a = b;
    b = temp; 
}
void swapping(const char* &a,const char* &b) // swap char pointers
{
    const char* temp = a;
    a = b;
    b = temp;   
}

int main(void) 
{
    int a = 7, b = 15;
    float x = 3.5, y = 9.2;
    const char *str1 = "One";
    const char *str2 = "Two";

    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;

    swapping(a, b);
    swapping(x, y);
    swapping(str1, str2);

    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    
    return 0;
}
