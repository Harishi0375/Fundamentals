/*
  CH-230-A
  a10_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

//used previous code from question 1
#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <string>

class Critter
{
private:
    std::string name;
    double hunger; // Change hunger to a double between 0.0 and 1.0
    int boredom;
    double height;
    int age;
    std::string gender;

public:
    double convertToDouble(int hungerLevel);
    int convertToInt(double hungerPercentage);
    // Constructors
    Critter();
    Critter(const std::string& newname);
    Critter(const std::string& newname, int newhunger, int newboredom, double newheight = 10.0);

    // Setter methods
    void setName(const std::string& newname);
    void setHunger(int newhunger);
    void setBoredom(int newboredom);
    void setAge(int newAge);
    void setGender(const std::string& newGender);

    // Getter methods
    int getHunger() const;
    int getAge() const;
    std::string getGender() const;

    // Service method
    void print() const;

private:
    // Private helper methods for hunger conversion
    double convertToDouble(int hungerLevel) const;
    int convertToInt(double hungerPercentage) const;
};

#endif // CRITTER_H


