// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"

using namespace std; 

Shape::Shape(const string& n) : name(n) {
    cout << "constructor shape" << endl;
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
    cout << "constructor CS" << endl;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	cout << "constructor RP" << endl;
    EdgesNumber = nl;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	cout << "constructor CIRCLE" << endl;
    Radius = r;
}