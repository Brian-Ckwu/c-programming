#include <stdio.h>

int main()
{
    // Declare variables and pointers
    int i = 1, j = 2;
    const int* ptr1 = &i; // Cannot change the value that the pointer pointed to, but can change which variable the pointer point
    int* const ptr2 = &i; // Cannot change the value of the pointer (the address stored), but can change the variable that the pointer pointed to
    const int* const ptr3 = &i; // Cannot change the value of the pointer itself and the value the pointer pointed to, but can still use the variable itself to change its value
    const int k = 3; // Can we use some pointers to change k's value? --> Yes, but this is not consistent
    int* ptr4 = &k; // <-- This will get a warning from the compiler, and the const keyword in the previous line would be discarded

    // Manipulation
    // *ptr = j; <-- This operation is not allowed
    ptr1 = &j; // <-- This is allowed
    i = 3; // We can still change the value of i itself (not through ptr1)
    *ptr2 = j; // <-- Valid
    // ptr2 = &j; <-- This operation is not allowed

    // Display results
    printf("The value of i: %d\n", i);
    printf("The value that the pointer ptr1 pointed to: %d\n", *ptr1);
    printf("The value that the pointer ptr2 pointed to: %d\n", *ptr2);
    printf("The value of k: %d", k);

    return 0;
}