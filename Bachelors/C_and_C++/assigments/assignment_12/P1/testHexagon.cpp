#include <iostream>
#include "Shapes.h"

int main() {
    Hexagon blueHexagon("Blue Hexagon", 0, 0, 9, "Blue");
    Hexagon greenHexagon("Green Hexagon", 0, 0, 15, "Green");
    Hexagon copiedHexagon = greenHexagon;

    std::cout << "Blue Hexagon:\n";
    std::cout << "Perimeter: " << blueHexagon.perimeter() << "\n";
    std::cout << "Area: " << blueHexagon.area() << "\n";
    std::cout << "Color: " << blueHexagon.getColour() << "\n\n";

    std::cout << "Green Hexagon:\n";
    std::cout << "Perimeter: " << greenHexagon.perimeter() << "\n";
    std::cout << "Area: " << greenHexagon.area() << "\n";
    std::cout << "Color: " << greenHexagon.getColour() << "\n\n";

    std::cout << "Copied Hexagon:\n";
    std::cout << "Perimeter: " << copiedHexagon.perimeter() << "\n";
    std::cout << "Area: " << copiedHexagon.area() << "\n";
    std::cout << "Color: " << copiedHexagon.getColour() << "\n";

    return 0;
} 
