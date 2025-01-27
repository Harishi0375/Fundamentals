/*
  CH-230-A
  a11_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Box.h"

using namespace std;

Box::Box() : height(0), width(0), depth(0) {} // Default

Box::Box(const Box& other) : height(other.height), width(other.width), depth(other.depth) {
    std::cout << "The copy constructor is called." << std::endl;
}

Box::Box(double newheight, double newwidth, double newdepth)
    : height(newheight), width(newwidth), depth(newdepth) {}

Box::~Box() {
    std::cout << "Destructor called." << std::endl;
}

void Box::setDepth(double newdepth) {
    depth = newdepth;
}

void Box::setHeight(double newheight) {
    height = newheight;
}

void Box::setWidth(double newwidth) {
    width = newwidth;
}

double Box::getHeight() const {
    return height;
}

double Box::getWidth() const {
    return width;
}

double Box::getDepth() const {
    return depth;
}

double Box::getVolume() const {
    return (height * width * depth);
}

void Box::print() {
    std::cout << "Box dimensions: Height = " << height << ", Width = " << width << ", Depth = " << depth << std::endl;
    std::cout << "Volume = " << getVolume() << std::endl;
}




