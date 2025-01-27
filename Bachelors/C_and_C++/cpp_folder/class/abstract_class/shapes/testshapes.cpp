#include "shapes.h"

int main(int argc, char** argv) {

  Circle c("first circle", 3, 4, 7);
  RegularPolygon r("TRIANGLE", 1, 1, 3);
  Circle a("Second circle",6,5,1); //my test

  Shape *p = new Circle("lol",3,4,7);

  // Shape s;  // would be illegal

  p->printName(); //prints: lol
  r.printName();
  c.printName();
  a.printName();
  r.draw();
  r.erase();
  c.draw();
  c.erase();
  a.draw();
  a.erase();
  delete p; // needed 
  return 0;
}