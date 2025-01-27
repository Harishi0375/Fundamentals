/*
  CH-230-A
  a10_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/


#include <iostream>
#include "City.h"

using namespace std;


/*I have changed the code a little bit by asking the user to input the city name*/
int main(int argc, char** argv)
{
    
    for (int i = 0; i < 3; i++)
    {
        City city; // class for Bremen,London,Paris

        string cityname;
        int newih;
        string newmayor;
        double newarea;

        cout << "Please enter city name: ";
        getline(cin, cityname);
        city.setCityname(cityname);
        cout << "Inhabitants: ";
        cin >> newih;
        city.setInhabitants(newih);
        cin.ignore(); // Ignore the newline character in the buffer
        cout << "Name of mayor: ";
        getline(cin, newmayor);
        city.setMayor(newmayor);
        cout << "Enter square area of city: ";
        cin >> newarea;
        city.setArea(newarea);
        cin.clear();
        fflush(stdin);

        cout << "You have created:" << endl;
        city.print();
    }
    
    return 0;
}