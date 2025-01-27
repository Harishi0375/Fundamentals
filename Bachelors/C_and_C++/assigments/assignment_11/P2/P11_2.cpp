/*
  CH-230-A
  a11_p2.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

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

    void climb() const;
};

class SeaCreature : public Creature {
protected:
    bool can_walk_on_land;
    string name;

public:
    SeaCreature(); // Default constructor
    ~SeaCreature();

    void jump() const;
};

class Wizard : public Creature {
public:
    Wizard();
    void hover() const;
};


Creature::Creature() : distance(10) {}

void Creature::run() const {
    cout << "running " << distance << " meters!\n";
}

LandCreature::LandCreature() : legs(4), fur(true), name("lion") {} //giving user input here

LandCreature::~LandCreature() {
    cout << "land creature destructor called." << endl;
}

void LandCreature::climb() const {
    string value = fur ? "fur" : "no fur"; 
    cout << "The land creature " << name << " has " << legs << " legs and " << value << endl;
}

SeaCreature::SeaCreature() : can_walk_on_land(false), name("gold fish") {} //giving user input here

SeaCreature::~SeaCreature() {
    cout << "sea creature destructor called." << endl;
}

void SeaCreature::jump() const {
    string value = can_walk_on_land ? "can walk on land" : "cannot walk on land";
    cout << "The sea creature " << name << " " << value << endl;
}

Wizard::Wizard() {}

void Wizard::hover() const {
    cout << "hovering " << (3 * distance) << " meters!\n";
}

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
    a.climb();
    cout << "\n";

    cout << "creating a sea creature\n";
    SeaCreature b;
    b.run();
    b.jump();
    cout << "\n";

    return 0;
}

