#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Area.h"

class Circle : public Area {
	public:
		Circle(const char *n, double a);
		~Circle();
		double calcArea() const override;
		double calcPer() const override;
		friend class Ring; //added this to find perimeter of ring 
	private:
		double radius;
};

#endif
