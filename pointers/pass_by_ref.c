#include <stdio.h>

void squareInt(int* ptr);

int main()
{
    // Declare
    int i = 5;
    printf("The integer i is orginally: %d\n", i);

    // Square the int
    squareInt(&i);

    // Display the squared int
    printf("The squared i is: %d", i);
}

void squareInt(int* ptr)
{
    *ptr = (*ptr) * (*ptr);
}