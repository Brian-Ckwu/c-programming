#include <stdio.h>
#include <stdlib.h>

int gcd(int u, int v);
float absoluteValue(float x);
float squareRoot(float x);

int main()
{
    int result = 0;

    result = gcd(35, 150);
    printf("The result is %d", result);

    return 0;
}

int gcd(int x, int y)
{
    int temp;

    while (y != 0) {
        temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}

float squareRoot(float x)
{
    const float epsilon = .00001;
    float guess = 1.0;
    float returnValue = 0.0;

    if (x < 0) {
        printf("Negative argument to squareRoot.\n");
        returnValue = -1.0;
    }
    else {
        while (absoluteValue(guess * guess - x) >= epsilon)
            guess = (x / guess + guess) / 2.0;
        returnValue = guess;
    }

    return returnValue;
}

float absoluteValue(float x)
{
    if (x < 0)
        x = -x;
    
    return x;
}