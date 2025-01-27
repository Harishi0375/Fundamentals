/*
  CH-230-A
  a12_p5.cpp
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

    

    // Determine the greater fraction
    if (a > b) {
        cout << "Greater fraction: " << a;
    } else {
        cout << "Greater fraction: " << b;
    }

    Fraction sum = a + b;
    Fraction difference = a - b;

    cout << "Sum: " << sum;
    cout << "Difference: " << difference;
      
    //i gave the answers in fractions
    //as how the values are entered
    return 0;
}
