#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTRIES 5
#define MINNUM 0
#define MAXNUM 20

int main()
{
    // Declare and initializing variables
    int triesLeft = MAXTRIES;
    int guessNumber;
    time_t t;
    // Generate a random number
    srand((unsigned) time(&t));
    int targetNumber = rand() % (MAXNUM + 1);

    // Guess loop
    printf("This is a number guessing game.\n");
    printf("I have chosen a number between %d and %d which you have to guess.\n", MINNUM, MAXNUM);
    while (triesLeft > 0)
    {
        // Get the guess from the user
        printf("\nYou have %d tries left.\n", triesLeft);
        printf("Please enter a guess: ");
        scanf("%d", &guessNumber);

        // Check if the entered number is valid
        if ((guessNumber < MINNUM) || (guessNumber > MAXNUM))
        {
            printf("\nInvalid input. The number must between %d and %d.\n", MINNUM, MAXNUM);
            continue;
        }

        // Check if the entered number equals to the answer
        if (guessNumber < targetNumber)
        {
            printf("The chosen number if greater than %d.\n", guessNumber);
        }
        else if (guessNumber > targetNumber) {
            printf("The chosen number is less than %d.\n", guessNumber);
        }
        else
        {
            printf("\nCongrats! Correct answer!\n");
            return 0;
        }
        triesLeft--;
    }

    // The user loses
    printf("\nThere are no tries left. You lost.");
    return 0;
}