#include <stdio.h>
#include <string.h>

// Define structures
struct Employee
{
    char name[20];
    int hireDate;
    float salary;   
};

int main()
{
    // Declare variables
    struct Employee employee =
    {
        "Nini Huang",
        20210608,
        300000.00
    };

    printf("Employee 1: %s %d %.2f\n", employee.name, employee.hireDate, employee.salary);

    printf("Please enter the data of the next employee (name hireDate salary): ");
    scanf("%s %d %f", employee.name, &(employee.hireDate), &(employee.salary)); // Beware of the difference
    printf("Employee 2: %s %d %.2f\n", employee.name, employee.hireDate, employee.salary);

    return 0;
}