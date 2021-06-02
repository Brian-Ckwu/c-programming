#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
#define YEARS 5

int main()
{
    // Initialize rainfall data for 2011-2015
    float rain[YEARS][MONTHS] = 
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {7.1, 7.1, 7.1, 7.1, 7.1, 7.1, 7.1 ,7.1, 7.1, 7.1, 7.1, 7.1},
        {5.1, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1},
        {6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1}
    };

    int year, month;
    float subtot, total;

    printf("YEAR\t\tRAINFALL  (inches)\n");

    for (year = 0, total = 0; year < YEARS; year++) {
        for (month = 0, subtot = 0; month < MONTHS; month++) {
            subtot += rain[year][month];
        }
        printf("%5d \t\t%15.1f\n", 2010 + year, subtot);
        total += subtot;
    }

    printf("\nThe yearly average is %.1f inches.\n\n", total/YEARS);

    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

    for (month = 0; month < MONTHS; month++) {
        for (year = 0, subtot = 0; year < YEARS; year++) {
            subtot += rain[year][month];
        }
        printf("%4.1f", subtot/YEARS);
    }

    printf("\n");

    return 0;
}