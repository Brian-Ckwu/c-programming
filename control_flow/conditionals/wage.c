#include <stdio.h>

void main()
{
    // Declaring and initializing variables
    float hoursWorked;
    float payRate = 12.00;
    float grossPay, taxes, netPay;

    // Read input (ask the user for working hours)
    printf("Hours worked per week: ");
    scanf("%f", &hoursWorked);

    // Calculation
    // Gross pay
    if (hoursWorked <= 40.0) {
        grossPay = hoursWorked * payRate;
    }   else {
        grossPay = (40.0 * payRate) + ((hoursWorked - 40.0) * payRate * 1.5);
    }
    // Taxes
    if (grossPay <= 300.0) {
        taxes = grossPay * 0.15;
    }   else if (grossPay <= 450.0) {
        taxes = (300.0 * 0.15) + ((grossPay - 300.0) * 0.20);
    }   else {
        taxes = (300.0 * 0.15) + (150.0 * 0.20) + ((grossPay - 450.0) * 0.25);
    }
    // Net pay
    netPay = grossPay - taxes;
    
    // Displaying output (grossPay, taxes, and netPay)
    printf("Gross pay: %f\nTaxes: %f\nNet pay: %f", grossPay, taxes, netPay);
}