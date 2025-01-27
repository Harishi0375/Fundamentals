/*
  CH-230-A
  a11_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Creature.h"

using namespace std;

int main() {
    cout << "Creating a Creature.\n";
    Creature c;
    c.run();
    cout << "\n";

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();
    cout << "\n";

    cout << "Creating a land creature\n";
    LandCreature a;
    a.run();
    a.print();
    cout << "\n";

    cout << "creating a sea creature\n";
    SeaCreature b;
    b.run();
    b.print();
    cout << "\n";

    return 0;
}