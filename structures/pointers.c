#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUTLEN 20

// Create structures (outside the int function so these structures can be used by other functions) (these definitions will not occupy memory)
struct Date {
    int year;
    int month;
    int day;
};

struct Time {
    int hour;
    int minute;
    int second;
};

struct DateAndTime {
    struct Date date;
    struct Time time;
};

struct NewTime {
    // Date
    struct {
        int year;
        int month;
        int day;
    } date;
    // Time
    int hour;
    int minute;
    int second;
} newtime;

// Function prototypes (for demonstration of usage of struct pointers)
void demoSyntax(void);
void demoNestedStruct(void);
void demoIntPointersInStruct(void);
void demoCharPointersInStruct(void);

int main()
{
    demoSyntax();
    demoNestedStruct();
    demoIntPointersInStruct();
    demoCharPointersInStruct();

    return 0;
}

void demoSyntax(void)
{
    struct Date* datePtr = NULL;
    struct Date today;

    datePtr = &today;

    // Ordinary syntax for pointers
    (*datePtr).month = 6;
    (*datePtr).day = 8;
    (*datePtr).year = 2021;

    printf("The size of an integer: %zu\n", sizeof(int));
    printf("The size of the pointer itself: %d\n", sizeof(datePtr));
    printf("The size of the variable pointed: %d\n", sizeof(*datePtr));
    printf("Today is %d-%02d-%02d\n", datePtr->year, datePtr->month, datePtr->day); // Syntax specifically for struct pointers
}

void demoNestedStruct(void)
{
    struct NewTime now =
    {
        {2021, 6, 8},
        14,
        50,
        27
    };
    struct NewTime future = {0};
    struct NewTime* ptr = &now;

    ptr = &future;
    ptr->date.month = 7;
    ptr->date.day = 22;
    ptr->date.year = 2021;
    
    ptr = &now;
    printf("\nCurrent time: %d-%02d-%02d %02d:%02d:%02d\n", ptr->date.year, ptr->date.month, ptr->date.day, ptr->hour, ptr->minute, ptr->second);
    printf("Future time: %d-%02d-%02d %02d:%02d:%02d\n", future.date.year, future.date.month, future.date.day, future.hour, future.minute, future.second);
}

void demoIntPointersInStruct(void)
{
    // Define the structure in this function so it's clearer (instead of on the top)
    struct IntPtrs
    {
        int* ptr1;
        int* ptr2;
    };

    // Declare variables
    struct IntPtrs intPointers = {NULL, NULL};
    int i1 = 100;
    int i2; // The memory would be allocated for i2 after this declaration (whether initialized or not)

    // Point to the variables
    intPointers.ptr1 = &i1;
    intPointers.ptr2 = &i2;

    // Assignment
    *(intPointers.ptr2) = -100;

    // Display the values
    printf("\nThe value of i1 is: %d\n", *(intPointers.ptr1));
    printf("The value of i2 is: %d\n", *intPointers.ptr2); // The dot operator has higher precedence over the dereference operator, the parenthesis only makes it clearer which operation takes place first
}

void demoCharPointersInStruct(void)
{
    // Two structs: one using character arrays and the other using character pointers
    struct CharArrays
    {
        char fname[20];
        char lname[20];
    };
    struct CharPointers
    {
        char* fname;
        char* lname;
    };

    // Declare variables
    struct CharArrays charArrays = {"Brian", "Wu"}; // This is okay, the strings would be stored in the structure
    struct CharPointers charPointers = {NULL, NULL}; // The strings are stored elsewhere if we initialized the structure here
    char temp[INPUTLEN];
    
    // Assign strings to charPointers
    // Read input from the user -> Allocate memory for the string first -> Assign
    // Might be more DRY using loop
    printf("\nPlease enter the first name: ");
    scanf("%s", temp);
    charPointers.fname = calloc(sizeof(temp) + 1, sizeof(char));
    strcpy(charPointers.fname, temp);
    printf("Please enter the last name: ");
    scanf("%s", temp);
    charPointers.lname = calloc(sizeof(temp) + 1, sizeof(char));
    strcpy(charPointers.lname, temp);

    // Display the sizes of the two structures
    printf("\nThe size of charArrays: %zu\n", sizeof(charArrays));
    printf("The size of charPointers: %zu\n", sizeof(charPointers));

    // Display the strings
    printf("The name in charArrays: %s %s\n", charArrays.fname, charArrays.lname);
    printf("The name in charPointers: %s %s\n", charPointers.fname, charPointers.lname);
}