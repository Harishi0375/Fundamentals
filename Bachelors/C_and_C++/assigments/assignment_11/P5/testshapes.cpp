/*
  CH-230-A
  a11_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

// Inside testsshape.cpp

#include "Shapes.h"

using namespace std;

int main(int argc, char** argv) {

    Circle c("first circle", 3, 4, 7);
    Rectangle rect("RECTANGLE", 2, 2, 4, 6);
    Square sq("SQUARE", 1, 1, 5);

    cout << "Circle Perimeter: " << c.perimeter() << ", Area: " << c.area() << endl;
    cout << "Rectangle Perimeter: " << rect.perimeter() << ", Area: " << rect.area() << endl;
    cout << "Square Perimeter: " << sq.perimeter() << ", Area: " << sq.area() << endl;

    return 0;
}
