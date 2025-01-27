/*
  CH-230-A
  a11_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

// please refer to shapes.h for methods documentation

#include "Shapes.h"

using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

void Circle::setRadius(int newradius)
{
    Radius = newradius;
}

int Circle::getRadius() const{
    return Radius;
}

double Circle::perimeter(){
    return (2 * M_PI * Radius);
}

double Circle::area(){
    return (M_PI * Radius * Radius);
}

Rectangle::Rectangle(const string &n, double nx, double ny, double nwidth,double nheight) : 
    RegularPolygon(n,nx,ny,4) //4 because rectangle has 4 sides 
{
    width = nwidth;
    height = nheight;
}

void Rectangle::setWidth(double nwidth)
{
    width = nwidth;
}

void Rectangle::setHeight(double nheight)
{
    height = nheight;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getHeight() const
{
    return height;
}

double Rectangle::perimeter(){
    return (2*(width+height));
}

double Rectangle::area(){
    return (width*height);
}

Square::Square(const string &n, double nx, double ny, double nside) : Rectangle(n, nx, ny, nside, nside) {
    sides = nside;
}


void Square::setSides(double nside)
{
    sides = nside;
}

double Square::getSides() const
{
    return sides;
}

double Square::perimeter(){
    return (4*sides);
}

double Square::area(){
    return (sides*sides);
}











