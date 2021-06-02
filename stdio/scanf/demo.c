#include <stdio.h>

void main()
{
    // Declaring variables (!= Initializing)
    char str[100];
    int i;
    double num;
    // Read the input
    printf("Enter string/integer:");
    i = scanf("%s %lf", str, &num);
    // Print the output
    printf("You entered %d words: %s %lf", i, str, num);
}