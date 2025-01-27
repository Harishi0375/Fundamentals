#ifndef _SQUARE_H
#define _SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle
{
    private:
        int side;
    public:
        ~Square();
        Square(const char *n,const int nside);
        double calcArea() const override;
		double calcPer() const override;
};

#endif