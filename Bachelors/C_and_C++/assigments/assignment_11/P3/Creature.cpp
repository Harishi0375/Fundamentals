/*
  CH-230-A
  a11_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature() : distance(10) {}

void Creature::run() const {
    cout << "running " << distance << " meters!\n";
}

LandCreature::LandCreature() : legs(4), fur(true), name("lion") {} //giving user input here

LandCreature::~LandCreature() {
    cout << "land creature destructor called." << endl;
}

void LandCreature::print() const {
    string value = fur ? "fur" : "no fur"; 
    cout << "The land creature " << name << " has " << legs << " legs and " << value << endl;
}

SeaCreature::SeaCreature() : can_walk_on_land(false), name("gold fish") {} //giving user input here

SeaCreature::~SeaCreature() {
    cout << "sea creature destructor called." << endl;
}

void SeaCreature::print() const {
    string value = can_walk_on_land ? "can walk on land" : "cannot walk on land";
    cout << "The sea creature " << name << " " << value << endl;
}

Wizard::Wizard() {}

void Wizard::hover() const {
    cout << "hovering " << (3 * distance) << " meters!\n";
}

