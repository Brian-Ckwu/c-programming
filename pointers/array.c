#include <stdio.h>

int arraySum(int array[], const int n); // Is the const int variable necessary?
int arraySumPtr(int* array, const int n);
int arraySumBad(int array[], const int n);

int main()
{
    // Declaration
    const int n = 10;
    int array[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int sum1, sum2, sum3;
    int* arrayPtr = array;

    // Calculation
    sum1 = arraySum(array, n);
    sum2 = arraySumPtr(array, n);
    sum3 = arraySumBad(array, n);

    // Display results
    printf("The result from arraySum(): %d\n", sum1);
    printf("The result from arraySumPtr(): %d\n", sum2);
    printf("The result from arraySumBad(): %d\n", sum3);

    return 0;
}

int arraySum(int array[], const int n)
{
    int sum = 0;

    for (int i = 0; i < n; sum += array[i++]);

    return sum;
}

int arraySumPtr(int* array, const int n)
{
    int sum = 0;
    int* const arrayEnd = array + n;

    for (; array < arrayEnd; array++)
        sum += *array;

    return sum;
}

int arraySumBad(int array[], const int n)
{
    int sum = 0;
    int* const arrayEnd = array + n;

    for (; array < arrayEnd; array++) // Not good convention to do so, should use array notation instead
        sum += *array;
    
    return sum;
}