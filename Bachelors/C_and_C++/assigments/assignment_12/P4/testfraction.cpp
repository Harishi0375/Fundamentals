/*
  CH-230-A
  a12_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
    // Fraction a(4, 2);
 	// Fraction b(17, 11);
 	// Fraction c(5);

    Fraction a, b;
    cout << "Enter the first fraction:" << endl;
    cin >> a;

    cout << "Enter the second fraction:" << endl;
    cin >> b;

    cout << "You entered: " << endl;
    cout << "First fraction: " << a;
    cout << "Second fraction: " << b;

    // Calculate and print the product
    Fraction product = a * b;
    cout << "Product: " << product;

    // Calculate and print the quotient
    Fraction quotient = a / b;
    cout << "Quotient: " << quotient;

    return 0;
}
