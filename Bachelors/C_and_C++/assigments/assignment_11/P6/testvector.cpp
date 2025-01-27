/*
  CH-230-A
  a11_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "Vector.h"

int main() {
    // Creating instances using different constructors
    Vector v1; // Default constructor
    double ptr2[] = {3.4, 2.1, 3.6};
    Vector v2(3, ptr2); // Parametric constructor

    Vector v3(v2); // Copy constructor
    double ptr4[] = {4.0, 5.0, 6.0};
    Vector v4(3, ptr4); // Parametric constructor

    // Computing and printing results
    std::cout << "Norm of v2: " << v2.norm() << std::endl;

    std::cout << "Scalar product of v2 and v4: " << v2.scalarProduct(v4) << std::endl;

    std::cout << "Sum of v2 and v4: ";
    (v2.add(v4)).print();

    std::cout << "Difference of v2 and v4: ";
    (v2.subtract(v4)).print();

    return 0;
}
