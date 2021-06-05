#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dynamicInput(void);

int main()
{
    dynamicInput();

    return 0;
}

void dynamicInput(void)
{
    // Declaration
    int length = 0;
    char* ptr = NULL;

    // Ask for input
    printf("How many characters do you want to enter: ");
    scanf("%d", &length);
    ptr = (char*) calloc(length + 1, sizeof(char)); // cast the void pointer
    // ptr = malloc((length + 1) * sizeof(char)); // or this
    if (ptr != NULL) { // Important to check if the memory was successfully allocated
        printf("Enter the string: ");
        scanf("%s", ptr);
    }

    // Display the result
    printf("\nThe string entered is: %s\n", ptr);

    // Free the memory
    free(ptr);
}