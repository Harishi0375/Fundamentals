#include <iostream>
#include "City.h"

using namespace std;

void City::setCityname(string& newCityname){
    cityName = newCityname;
}

void City::setInhabitants(int newIh){
    inhabitants = newIh;
}

void City::setMayor(string& newMayor){
    mayor = newMayor;
}

void City::setArea(double newArea){
    area = newArea;
}

void City::print() {
	cout << "In " << cityName << " the number of inhabitantants are: " << inhabitants << " .The mayor is " << mayor << " and the area of the city in kmsq is: " << area << endl;
}

std::string City::getCityname() {
	return cityName;
}

int City::getInhabitants() {
	return inhabitants;
}

std::string City::getMayor(){
  return mayor;
}

double City::getArea() {
	return area;
}