#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Object3D
{
protected:
    string name;

public:
    virtual void volume() = 0; // Pure virtual function
    Object3D(const string &na) : name(na) {}
    virtual ~Object3D() {}
};

class Sphere : public Object3D
{
private:
    float radius;

public:
    void volume() override; // Provide a definition for the pure virtual function
    Sphere(const string &na,float nradius) : Object3D(na),radius(nradius) {}
};

class Cylinder : public Object3D
{
private:
    float radius;
    float height;

public:
    void volume() override; // Provide a definition for the pure virtual function
    Cylinder(const string &na,float nradius,float nheight) : Object3D(na),radius(nradius), height(nheight) {}
};

class Cube : public Object3D
{
private:
    float side;

public:
    void volume() override; // Provide a definition for the pure virtual function
    Cube(const string &na,float nside) : Object3D(na),side(nside) {}
};

class RectPrism : public Object3D
{
private:
    float width, length, height;

public:
    void volume() override; // Provide a definition for the pure virtual function
    RectPrism(const string &na,float nwidth, float nlength, float nheight);
};

RectPrism::RectPrism(const string &na,float nwidth, float nlength, float nheight) : Object3D(na),width(nwidth), length(nlength), height(nheight) {}

// Implement the volume functions
void Sphere::volume()
{
    cout << "volume of sphere: " << flush;
    cout << (M_PI * radius * radius * (4/3)) << endl;
}

void Cylinder::volume()
{
    cout << "volume of cylinder: " << flush;
    cout << (M_PI * radius * radius * height) << endl; 
}

void Cube::volume()
{
    cout << "volume of Cube: " << flush;
    cout << (side * side * side) << endl;
}

void RectPrism::volume()
{
    cout << "volume of RectPrism: " << flush;
    cout << (width * length * height) << endl;
}

int main() 
{
    Object3D *arr[5];
    arr[0] = new Sphere("sphere", 1.3);
    arr[1] = new RectPrism("rectprism", 2.0, 3.0, 4.0);
    arr[2] = new Cylinder("cylinder", 2.0, 1.3);
    arr[3] = new Cube("cube", 2.0);
    arr[4] = new RectPrism("rectprism2", 1.0, 2.0, 3.5);
    
    for(int i=0; i<5; i++)
        arr[i]->volume();
    for(int i=0; i<5; i++)
        delete arr[i];
    return 0;
}




