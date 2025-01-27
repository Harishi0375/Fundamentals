/*
  CH-230-A
  a10_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"

using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::setAge(int newAge){
  age = newAge;
}

void Critter::setGender(string& newGender){
  gender = newGender;
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
}

int Critter::getHunger() {
	return hunger;
}

int Critter::getAge() {
	return age;
}

int Critter::getHunger() {
	return hunger;
}

std::string Critter::getGender(){
  return gender
}


