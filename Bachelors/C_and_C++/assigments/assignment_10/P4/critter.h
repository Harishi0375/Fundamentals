/*
  CH-230-A
  a10_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

// used previous code from question 1
#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <string>

class Critter
{
private:
    std::string name;
    int hunger;
    int boredom;
    double height;
    int age;
    std::string gender;

public:
    // Constructors
    Critter();
    Critter(const std::string &newname);
    Critter(const std::string &newname, int newhunger, int newboredom, double newheight = 10.0);

    // Setter methods
    void setName(const std::string &newname);
    void setHunger(int newhunger);
    void setBoredom(int newboredom);
    void setAge(int newAge);
    void setGender(const std::string &newGender);

    // Getter methods
    int getHunger() const;
    int getAge() const;
    std::string getGender() const;

    // Service method
    void print() const;
};

#endif // CRITTER_H
