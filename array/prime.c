#include <stdio.h>
#include <math.h>

int main()
{
    // Create an array which stores prime numbers, initialize the array with initial value 2
    int primeNumbers[100000] = {2};
    int targetNumber = 1000000;
    int loc = 1;

    // Loop through 3-targetNumber
    _Bool isPrime;
    for (int i = 3; i <= targetNumber; i += 2) { // Skipping the even numbers
        isPrime = 1;

        for (int j = 0; j < loc; j++) {
            // If all of the prime numbers less than the square root of the number have already been checked, stop checking
            if (pow(primeNumbers[j], 2) > i) {
                break;
            }
            // If the number can divide any of the exising prime numbers in the array, stop checking
            if ((i % primeNumbers[j]) == 0) {
                isPrime = 0;
                break;
            }
        }
        // If the number is not a prime number, continue
        if (!isPrime) {
            continue;
        }
        // Otherwise, append the number to the array of prime numbers
        primeNumbers[loc] = i;
        loc++;
    }

    // Display the prime numbers & total count
    for (int i = 0; i < loc; i++) {
        printf("%d ", primeNumbers[i]);
    }
    printf("\nThere are %d prime numbers between 1 and %d.\n", loc, targetNumber);

    return 0;
}