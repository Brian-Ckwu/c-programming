#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YEARS 5
#define MONTHS 12
#define MAXRAINFALL 10.0

int main()
{
    // Declare variables and create an array to store rainfall data
    float rainfalls[YEARS][MONTHS];
    float rainfall = 0.0;
    float yearlyAvg = 0.0;
    float yearSums[YEARS] = {0.0};
    float monthlyAvgs[MONTHS] = {0.0};
    time_t t;

    // Generate random rainfall data and assign the values to the array
    srand((unsigned) time(&t));
    int i, j;
    for (i = 0; i < YEARS; i++) {
        for (j = 0; j < MONTHS; j++) {
            rainfalls[i][j] = (float) rand() / RAND_MAX * 10.0;
        }
    }

    // Display the whole array and calculate the value as needed
    printf("\n\nThe rainfall data:\n\n");
    // The months
    printf("\t");
    for (i = 1; i <= MONTHS; i++) {
        printf("%02d\t", i);
    }
    // Year sum column
    printf("YEARSUM");
    for (i = 0; i < YEARS; i++) {
        // The years
        printf("\nYEAR%d\t", i + 1);
        for (j = 0; j < MONTHS; j++) {
            rainfall = rainfalls[i][j];
            printf("%.1f\t", rainfall);
            // Calculate year sum & monthly average
            yearSums[i] += rainfall;
            monthlyAvgs[j] += (rainfall / YEARS);
        }
        // Display year sum of rainfall & add 1/YEARS of the year sum to yearlyAvg
        printf("%.1f", yearSums[i]);
        yearlyAvg += yearSums[i] / YEARS;
    }
    // Display monthly average & yearly average
    printf("\nAVG\t");
    for (j = 0; j < MONTHS; j++) {
        printf("%.1f\t", monthlyAvgs[j]);
    }
    printf("%.1f", yearlyAvg);

    // Calculation
    return 0;
}