/*
    Demonstration of:
        1. Returning structs or struct pointers from a function
*/

#include <stdio.h>
#include <stdlib.h>

// Define structures
struct Date
{
    int year;
    int month;
    int day;
};

// Function prototypes
struct Date getDate(void);
struct Date* getDatePtr(void);
struct Date* getDatePtr2(void);

int main()
{
    struct Date date = {0};
    struct Date* datePtr = NULL;

    // printf("Before asssignment: %04d-%02d-%02d\n", date.year, date.month, date.day);

    // date = getDate();

    // printf("After assignment: %04d-%02d-%02d\n", date.year, date.month, date.day);

    datePtr = getDatePtr();
    printf("The address of the data pointed by datePtr (this line is outside the function): %p\n", datePtr);
    printf("Value of datePtr after assignment:  %04d-%02d-%02d\n", datePtr->year, datePtr->month, datePtr->day);

    return 0;
}

struct Date getDate(void)
{
    struct Date date = {0};

    printf("Please enter the date (year month day): ");
    scanf("%d %d %d", &(date.year), &(date.month), &(date.day));

    return date;
}

struct Date* getDatePtr(void)
{
    // Question: is the values of local variables still stored in the memory after the function call?
    // Let's try
    struct Date* datePtr = calloc(1, sizeof(struct Date));

    // Read input
    printf("Please enter the date (year month day): ");
    scanf("%d %d %d", &(datePtr->year), &(datePtr->month), &(datePtr->day));
    printf("The address of the data pointed by datePtr (this line is inside the function): %p\n", datePtr);

    return datePtr;
}

struct Date* getDatePtr2(void)
{
    // Another approach, will it work?
    struct Date date = {0};
    struct Date* datePtr = &date;

    printf("Please enter the date (year month day): ");
    scanf("%d %d %d", &(date.year), &(date.month), &(date.day));
    printf("The address of the data pointed by datePtr (this line is inside the function): %p\n", datePtr);

    return datePtr; // Won't work. The data of local variables will be cleared after the function call
}