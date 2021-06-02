#include <stdio.h>

int main()
{
    // Declare variables & create an array
    int count = 10;
    int scores[count];
    long sum = 0;
    float avg;

    // Use a loop to store the scores in the array
    printf("\nPlease enter the scores:\n");
    for (int i = 0; i < count; i++) {
        printf("%d> ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    // Calculate the average
    avg = (float) sum / count;

    // Display the results
    printf("\nThe average score: %f", avg);

    return 0;
}