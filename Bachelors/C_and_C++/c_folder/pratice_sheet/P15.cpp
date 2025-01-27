#include <iostream>

using namespace std;
class Car
{
    private:
        string name;
        string model;
        int price;
    public:
        Car(const string &newName,const string &newmodel,const int newPrice) : name(newName), model(newmodel), price(newPrice) {}
        ~Car();

        inline void setName(const string &newName) {name = newName;}
        inline void setModel(const string &newmodel) {model = newmodel;}
        inline void setPrice(const int newPrice) {price = newPrice;}
        friend Taxi;
};

class Taxi : public Car
{
    private:
        int limit;
    public:
        Taxi(const string &newName,const string &newmodel,const int newprice,const int newLimit);
        ~Taxi();
        void print();
        inline void setLimit(const int newLimit) {limit = newLimit;}
};

Taxi::Taxi(const string &newName,const string &newmodel,const int newprice,const int newLimit) : Car(newName,newmodel,newprice)
{
    limit = newLimit;
}

void Taxi::print()
{
    cout << "Brand name: " << name << endl;
    cout << "Model name: " << model << endl;
    cout << "Price: " << price << endl;
    cout << "Seating limit: " << limit << endl;
}