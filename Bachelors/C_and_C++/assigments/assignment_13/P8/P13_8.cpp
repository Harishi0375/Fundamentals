/*
  CH-230-A
  a13_p8.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


//ordered the class
class Motor
{
public:
    Motor()
    {
        throw runtime_error("motor does not work");
    }
};

class Car
{
public:
    Car()
    {
        try
        {
            Motor carMotor; // Declare the motor before using it
        }
        catch (const exception &obj)
        {
            throw runtime_error("car motor not working: " + string(obj.what()));
        }
    }
};

class Garage
{
private:
    Car garageCar;

public:
    Garage()
    {
        try
        {
            Car garageCar; // Declare the car before using it
        }
        catch (const exception &obj)
        {
            throw runtime_error("car's in garage not working" + string(obj.what()));
        }
    }
};

int main()
{
    try
    {
        // Attempt to create a Garage object
        Garage myGarage;
    }
    catch (const exception &obj)
    {
        // Catch and handle the exception thrown by the Garage class
        std::cerr << "Caught exception in main: " << obj.what() << std::endl;
    }

    return 0;
}
