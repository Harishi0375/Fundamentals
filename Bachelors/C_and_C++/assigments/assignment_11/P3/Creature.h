/*
  CH-230-A
  a11_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

//Creature.h
#ifndef _CREATURE_H
#define _CREATURE_H

#include <iostream>

using namespace std;

class Creature {
public:
    Creature();
    void run() const;

protected:
    int distance;
};

class LandCreature : public Creature {
protected:
    int legs;
    bool fur;
    string name;

public:
    LandCreature(); // Default constructor
    ~LandCreature();

    void print() const;
};

class SeaCreature : public Creature {
protected:
    bool can_walk_on_land;
    string name;

public:
    SeaCreature(); // Default constructor
    ~SeaCreature();

    void print() const;
};

class Wizard : public Creature {
public:
    Wizard();
    void hover() const;
};

#endif