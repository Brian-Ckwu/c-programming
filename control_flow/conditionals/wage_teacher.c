#include <stdio.h>
#include <stdlib.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
    // declare variables
    int hours = 0;
    double grossPay = 0.0;
    double taxes = 0.0;
    double netPay = 0.0;

    // get the input
    printf("Please enter the number of hours worked this week: ");
    scanf("%d", &hours);

    // calculate the gross pay
    if (hours <= OVERTIME)
        grossPay = hours * PAYRATE;
    else 
    {
        grossPay = OVERTIME * PAYRATE;
        double overTimePay = (hours - OVERTIME) * (PAYRATE * 1.5);
        grossPay += overTimePay;
    }

    // calculate taxes
    if (grossPay <= 300)
    {
        taxes = grossPay * TAXRATE_300;
    }
    else if ((grossPay > 300) && (grossPay <= 450))
    {
        taxes = 300 * TAXRATE_300;
        taxes += (grossPay - 300) * TAXRATE_150;
    }
    else
    {
        taxes = 300 * TAXRATE_300;
        taxes += 150 * TAXRATE_150;
        taxes += (grossPay - 450) * TAXRATE_REST;
    }

    // calculate the netPay
    netPay = grossPay - taxes;

    // display output
    printf("Gross pay: %.2f\n", grossPay);
    printf("Gross pay: %.2f\n", taxes);
    printf("Gross pay: %.2f\n", netPay);

    return 0;
}