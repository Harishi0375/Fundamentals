#include <iostream>
#include <cmath>
#include "Shapes.h"

using namespace std;

// Implementations for Shape class

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
    cout << name << endl;
}

// Implementations for CenteredShape class

CenteredShape::CenteredShape(const string& n, double nx, double ny) : Shape(n) {
    x = nx;
    y = ny;
}

void CenteredShape::move(double dx, double dy) {
    x += dx;
    y += dy;
}

// Implementations for RegularPolygon class

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
    CenteredShape(n, nx, ny) {
    EdgesNumber = nl;
}

RegularPolygon::RegularPolygon() : CenteredShape("Default RegularPolygon", 0, 0), EdgesNumber(0) {
}

RegularPolygon::RegularPolygon(const RegularPolygon& other) : CenteredShape(other), EdgesNumber(other.EdgesNumber) {
}

// Implementations for Circle class

Circle::Circle(const string& n, double nx, double ny, double r) :
    CenteredShape(n, nx, ny) {
    Radius = r;
}

// Implementations for Hexagon class

Hexagon::Hexagon(const string& n, double nx, double ny, int nside, const string& ncolour) :
    RegularPolygon(n, nx, ny,6), side(nside), colour(ncolour) {
}

Hexagon::Hexagon(const Hexagon& other) : RegularPolygon(other), side(other.side), colour(other.colour) {
}

Hexagon::~Hexagon() {
}

void Hexagon::setSide(int nside) {
    side = nside;
}

int Hexagon::getSide() const {
    return side;
}

void Hexagon::setColour(const string& ncolour) {
    colour = ncolour;
}

string Hexagon::getColour() const {
    return colour;
}

double Hexagon::perimeter() const {
    return 6 * side;
}

double Hexagon::area() const {
    return (3.0 * sqrt(3.0) / 2.0) * pow(static_cast<double>(getSide()), 2);
}
