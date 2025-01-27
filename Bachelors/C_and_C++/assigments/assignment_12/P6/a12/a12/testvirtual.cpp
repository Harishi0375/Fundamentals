/*
  CH-230-A
  a12_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <random>
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"

const int num_obj = 25;

/*               Area
                  ^         
				/    \
			   /      \
		 Circle  	   Rectangle
		  ^               ^
		  |               |
		Ring            Square
*/

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> size_dist(5.0, 100.0);
    std::uniform_int_distribution<int> color_dist(0, 3);  // 0: RED, 1: BLACK, 2: VIOLET, 3: BLUE

    Area* list[num_obj];
    // double sum_area = 0.0;
    // double sum_perimeter = 0.0;

    for (int i = 0; i < num_obj; ++i) {
        // Randomly choose the type of object
        int object_type = i % 4;  // 0: Circle, 1: Ring, 2: Rectangle, 3: Square

        // Randomly choose the color
        const char* colors[] = { "RED", "BLACK", "VIOLET", "BLUE" };
        const char* random_color = colors[color_dist(gen)];

        // Randomly choose the size
        double size = size_dist(gen);

        switch (object_type) {
            case 0:  // Circle
                list[i] = new Circle(random_color, size);
                break;
            case 1:  // Ring
                list[i] = new Ring(random_color, size, size / 2.0);
                break;
            case 2:  // Rectangle
                list[i] = new Rectangle(random_color, size, size * 1.5);
                break;
            case 3:  // Square (assumed to be a special case of Rectangle with equal sides)
                list[i] = new Square(random_color, size);
                break;
        }
    }

    for (int i = 0; i < num_obj; ++i) {
        list[i]->getColor();
        double area = list[i]->calcArea();
        double perimeter = list[i]->calcPer();
        std::cout << "Area: " << area << " units, Perimeter: " << perimeter << " units" << std::endl;
        delete list[i];  // Don't forget to free the allocated memory
    }

    return 0;
}


