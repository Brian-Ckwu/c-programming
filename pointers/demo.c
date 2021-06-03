#include <stdio.h>

// Demonstrate the address, size, and value of a variable and the pointer which points to it
int main()
{
    // Declare variables and pointers
    int i = 0;
    int* ptr = NULL;

    // Point to the the variable
    ptr = &i;

    // Change the value of the variable
    i = 10;

    // Display the information of the variable
    printf("The address of the variable: %p\n", &i);
    printf("The size of the variable: %zu\n", sizeof(i));
    printf("The value of the variable: %d\n\n", i);

    // Display the information of the pointer
    printf("The address of the pointer: %p\n", (void*)&ptr);
    printf("The size of the pointer: %zu\n", sizeof(ptr));
    printf("The value of the pointer (the address it stored): %p\n", ptr);
    printf("The value which the pointer pointed to: %d\n", *ptr);
    printf("The size of the value the pointer ptr pointed to: %zu\n", sizeof(*ptr));

    return 0;
}