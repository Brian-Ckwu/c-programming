#include <stdio.h>

int main()
{
    // Declare
    int i = 10;
    int* ptr = NULL;
    ptr = &i;

    // Display
    printf("Address of ptr: %p\n", (void*)&ptr);
    printf("The value of ptr: %p\n", ptr);
    printf("The address of the variable pointed by ptr: %p\n", &i);
    printf("The value ptr pointed to: %d\n", *ptr);

    return 0;
}