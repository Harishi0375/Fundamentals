/*
  CH-230-A
  a10_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <string> // defines standard C++ string class

class City
{
private:
    std::string cityName;
    int inhabitants;
    std::string mayor;
    double area;

public:
    //setters
    void setCityname(std::string& newCityname);
    void setInhabitants(int newIh);
    void setMayor(std::string& newMayor);
    void setArea(double newArea);

    //getters
    std::string getCityname();
    int getInhabitants();
    std::string getMayor();
    double getArea();

    // service method
	void print();

};
