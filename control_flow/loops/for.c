#include <stdio.h>

// Demonstrate for loops by calculating summation
void main()
{
    // Declare variables
    unsigned int sum1 = 0, sum2 = 0;
    unsigned int count;

    // Read input
    printf("Count from 1 to: ");
    scanf("%u", &count);

    // For loops
    for (unsigned int i = 1; i <= count; i++) {
        sum1 += i;
    }

    for (unsigned int i = 1; i <= count; sum2 += i++);
    // Display output
    printf("Summation from 1st for loop: %u\n", sum1);
    printf("Summation from 2nd for loop: %u", sum2);
}