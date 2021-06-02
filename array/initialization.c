#include <stdio.h>

int main()
{
    // Create and initialize an array
    int count = 20;
    int arr[20] = {1}; // Cannot use count as array length, why?

    // Display the values in the array
    for (int i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}