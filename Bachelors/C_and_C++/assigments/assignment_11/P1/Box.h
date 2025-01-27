/*
  CH-230-A
  a11_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>

class Box {
private:
    double height, width, depth;

public:
    // Constructors
    Box();                  // Default constructor
    Box(const Box& other);  // Copy constructor
    Box(double newheight, double newwidth, double newdepth);
    ~Box(); // Destructor

    // Setters
    void setHeight(double newheight);
    void setWidth(double newwidth);
    void setDepth(double newdepth);

    // Getters
    double getHeight() const;
    double getWidth() const;
    double getDepth() const;
    double getVolume() const;

    void print();
};
