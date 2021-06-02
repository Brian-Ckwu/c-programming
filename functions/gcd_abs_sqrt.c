#include <stdio.h>
#include <math.h>

void chooseTask(void);
int gcd(int x, int y);
float absoluteValue(float x);
float squareRoot(float x);

int main()
{
    // Declare variables
    int task = 0;
    int x, y;
    float z;
    float result;

    // Choose which calculation task to perform
    while (task == 0) {
        // Display choose menu
        chooseTask();
        scanf("%d", &task);
        // Choose
        switch (task) {
            case 1:
                printf("Please enter two numbers: ");
                scanf("%d %d", &x, &y);
                result = gcd(x, y);
                break;
            case 2:
                printf("Please enter the number: ");
                scanf("%f", &z);
                result = absoluteValue(z);
                break;
            case 3:
                printf("Please enter the number: ");
                scanf("%f", &z);
                result = squareRoot(z);
                break;
            default:
                printf("\nPlease choose from 1 to 3.\n\n");
                task = 0;
                break;
        }
    }

    // Display the result
    printf("The result is: %.2f", result);
}

void chooseTask(void)
{
    printf("1. Greatest common divisor\n");
    printf("2. Absolute value\n");
    printf("3. Sqaure root\n");
    printf("\nChoose which task to perform: ");
}

int gcd(int x, int y)
{
    if ((x < 0) || (y < 0)) {
        printf("Both numbers must be positive integers.\n");
        return -1;
    }
    else {
        if (x >= y) {
            if (y == 0) {
                return x;
            }
            else {
                return gcd(y, x % y);
            }
        }
        else {
            return gcd(y, x);
        }
    }
}

float absoluteValue(float x)
{
    float result = x;

    if (x < 0)
        result = -x;
    
    return result;
}

float squareRoot(float x)
{
    float result;

    if (absoluteValue(x) != x)
        result = -1.0;
    else
        result = sqrt(x);
    
    return result;
}