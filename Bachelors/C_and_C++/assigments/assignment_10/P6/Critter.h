/*
  CH-230-A
  a10_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

//used previous code from question 1
#include <string>
#include <iostream>

class Critter
{
private:
    std::string name;
    double hunger;
    int boredom;
    double height;
    int age;
    std::string gender;
    double thirst; // Added thirst level

public:
    // Constructors
    Critter();
    Critter(const std::string& newname);
    Critter(const std::string& newname, int newhunger, int newboredom, double newheight);
    Critter(const std::string& newname, int newhunger, int newboredom, double newheight, double newthirst);

    // Setter methods
    void setName(const std::string& newname);
    void setHunger(int newhunger);
    void setBoredom(int newboredom);
    void setAge(int newAge);
    void setGender(const std::string& newGender);
    void setThirst(double newThirst);

    // Getter methods
    int getHunger() const;
    int getAge() const;
    std::string getGender() const;
    double getThirst() const; // Getter for thirst

    // Service method
    void print() const;
    double convertToDouble(int hungerLevel);
    int convertToInt(double hungerPercentage);
};



