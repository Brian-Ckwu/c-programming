#include <stdio.h>

#define C1 2.0

void printConstants(void);

int main()
{
    const float C2 = 2.00;
    printConstants();
    printf("%f %f", C1, C2);

    return 0;
}

void printConstants(void)
{
    printf("%f\n", C1);
}