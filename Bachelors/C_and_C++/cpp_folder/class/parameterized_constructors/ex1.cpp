#include <iostream>

class Rectangle {
public:
    // Default constructor
    Rectangle() {
        width = 0;
        height = 0;
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor
    Rectangle(int w, int h) {
        width = w;
        height = h;
        std::cout << "Parameterized constructor called." << std::endl;
    }

    // Member function to calculate the area
    int calculateArea() {
        return width * height;
    }

private:
    int width;
    int height;
};

int main() {
    // Creating objects using different constructors
    Rectangle defaultRect;          // Default constructor called
    Rectangle customRect(4, 5);     // Parameterized constructor called

    // Using member function to calculate area
    std::cout << "Area of default rectangle: " << defaultRect.calculateArea() << std::endl;
    std::cout << "Area of custom rectangle: " << customRect.calculateArea() << std::endl;

    return 0;
}
