#include "shapes.h"

int main()
{
    Circle c("first circle", 3, 4, 7);
    RegularPolygon r("Triangle",1,1,3); 

    c.printName();
    r.printName();

    return 0;
}