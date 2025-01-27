#include <stdio.h>

// Function declaration
int rect_area(int length, int width);

int main() {
    int length, width;
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);

    // Calculate the area using the rect_area function
    int area1 = rect_area(length, width);

    // Display the result
    printf("The area of the rectangle is: %d\n", area1);

    return 0;
}

// Function definition for rect_area
int rect_area(int length, int width) {
    int area = length * width;
    return area;
}

