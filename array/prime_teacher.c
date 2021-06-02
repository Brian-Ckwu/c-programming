#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int p;
    int i;

    int primes[50] = {0};
    int primeIndex = 2;

    bool isPrime;

    // hardcode the first two prime numbers
    primes[0] = 2;
    primes[1] = 3;

    for (p = 5; p <= 100; p += 2) {
        isPrime = true;
        for (i = 0; isPrime && p / primes[i] >= primes[i]; i++) {
            if (p % primes[i] == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            primes[primeIndex] = p;
            primeIndex++;
        }
    }

    for (int i = 0; i < primeIndex; i++) {
        printf("%d ", primes[i]);
    }

    return 0;
}