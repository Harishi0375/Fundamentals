#include <iostream>
#include "Square.h"

Square::Square(const char *n,const int nside) : Rectangle(n,nside,nside) {
}

Square::~Square() {
}

double Square::calcArea() const {
	std::cout << "calcArea of Square...";
	return Rectangle::calcArea();
}

double Square::calcPer() const {
	std::cout << "calcPerimeter of Square...";
	return Rectangle::calcPer();
}