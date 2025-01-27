/*
  CH-230-A
  a11_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>
#include <iostream>
#include <math.h> //for the use of pi

# define M_PI   3.14159265358979323846  /* pi */

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
        void setName(std::string &newname); //setter
        

		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  
};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x,y;  // the center of the shape
	public:
        //setters
        void setX(double nx);
        void setY(double ny);

        //getters
        double getX() const;
        double getY() const;

		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&); //copy constructor
		void move(double, double);	// moves the shape, i.e. it modifies it center
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	private: 
		int EdgesNumber;
	public:
        void setEdgesnumber(int edge); //setter

        int getEdgesnumber() const; //getter

		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon(); //default constructor
		RegularPolygon(const RegularPolygon&); //copy constructor
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	private:
		double Radius;
	public:
        void setRadius(int newradius); //setter

        int getRadius() const; //getter

        double perimeter();
        double area();

		Circle(const std::string&, double, double, double);
		Circle(); //default constructor
		Circle(const Circle&); //copy constructor
};

class Rectangle : public RegularPolygon{ //a rectangle has 4 sides where opposite sides are equal 
    private:
        double width,height;
    public:
        void setWidth(double nwidth);
        void setHeight(double nheight); //setters

        double getWidth() const; //getters
        double getHeight() const;

        double perimeter();
        double area();
    
        Rectangle(const std::string&,double,double,double,double);
        Rectangle(); //default constructor
        Rectangle(const Rectangle&); //copy constructor
};

class Square : public Rectangle{ //square is a type of rectangle where all sides are equal 
    private:
        double sides;
    public:
        void setSides(double nside); //setter

        double getSides() const; //getter

        double perimeter();
        double area();

        Square(const std::string&,double,double,double);
        Square(); //default constructor
        Square(const Square&); //copy constructor
};
    
#endif