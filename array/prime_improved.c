#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Create an array which stores prime numbers, initialize the array with initial value 2
    int primeNumbers[100000] = {2};
    int targetNumber = 1000000;
    int loc = 1;
    bool isPrime;

    // Loop through 3-targetNumber to find prime numbers
    for (int i = 3; i <= targetNumber; i += 2) { // Skipping the even numbers
        isPrime = true;
        for (int j = 0; (isPrime) && (primeNumbers[j] * primeNumbers[j] <= i); j++) { // If all of the prime numbers less than the square root of the number have already been checked, stop checking
            // If the number can divide any of the exising prime numbers in the array, stop checking
            if ((i % primeNumbers[j]) == 0) {
                isPrime = false;
            }
        }
        // If the number is prime, append the number to the array of prime numbers
        if (isPrime) {
            primeNumbers[loc] = i;
            loc++;
        }
    }

    // Display the prime numbers & total count
    for (int i = 0; i < loc; i++) {
        printf("%d ", primeNumbers[i]);
    }
    printf("\nThere are %d prime numbers between 1 and %d.\n", loc, targetNumber);

    return 0;
}