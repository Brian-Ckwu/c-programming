#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    // Declaring variables
    double height, width;
    double perimeter, area;
    // Read the input
    printf("Please enter the height and width of the rectangle: ");
    scanf("%lf %lf", &height, &width);
    // Calculation
    perimeter = 2 * (height + width);
    area = height * width;
    // Display the output
    printf("Height: %.2f / Width: %.2f / Perimeter: %.2f\n", height, width, perimeter);
    printf("Height: %.2f / Width: %.2f / Area: %.2f", height, width, area);
}