#include <stdio.h>

void main()
{
    // Declaring variables
    int minutes;
    double days;
    int years;
    // Read the input
    printf("How many minutes: ");
    scanf("%d", &minutes);
    // Calculation
    days = minutes / (60.0 * 24); // Implicit type conversion
    years = days / 365;
    days -= years * 365;
    // Displaying results
    printf("%d minute(s) equal to %d year(s) and %lf day(s)", minutes, years, days);
}