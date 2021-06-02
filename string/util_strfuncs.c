#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverseStrcpy(char s1[], const char s2[]);
void reversePrint(const char str[]);
void testArrayOfStrings(void);
void readAndSortStrings(void);

int main()
{
    char s1[] = "123456789";
    char s2[] = "abcde";

    reversePrint(s1);

    // reverseStrcpy(s1, s2);
    // printf("After reverseStrcpy:\n");
    // printf("s1: %s\n", s1);
    // printf("s2: %s\n", s2);

    // testArrayOfStrings();

    // readAndSortStrings();
    
    return 0;
}

void reverseStrcpy(char s1[], const char s2[])
{
    int loc = strlen(s2) - 1;

    for (int i = 0; i <= loc; i++)
        s1[i] = s2[loc - i];

    s1[loc + 1] = '\0';
}

void reversePrint(const char str[])
{
    for (int loc = strlen(str) - 1; loc >= 0; loc--)
        printf("%c", str[loc]);
    printf("\n");
}

void testArrayOfStrings(void)
{
    char array[2][10] =
    {
        "First",
        "Second"
    };
    char temp[10];

    // Swap the strings
    strcpy(temp, array[0]);
    strcpy(array[0], array[1]);
    strcpy(array[1], temp);

    // Display the strings
    for (int i = 0; i < 2; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

void readAndSortStrings(void)
{
    // Initialize some variables & constants
    int stringNum = 3;
    const int kStringLen = 10;
    printf("How many strings do you want to enter: ");
    scanf("%d", &stringNum);

    // Create the array of strings
    char array[stringNum][kStringLen];

    // Read the input
    printf("Please enter %d strings:\n\n", stringNum);
    for (int i = 0; i < stringNum; i++) {
        printf("    %d> ", i + 1);
        scanf("%s", array[i]);
    }

    // Sort the strings
    char temp[kStringLen];
    bool isSorted = false;
    // Outer loop: keep looping through the strings until it's fully sorted
    while (!isSorted) {
        isSorted = true;
        // Inner loop: loop through the array
        for (int i = 0; i < stringNum - 1; i++) {
            // If the order is not right, swap the two elements
            if (strcmp(array[i], array[i + 1]) > 0) {
                strcpy(temp, array[i]);
                strcpy(array[i], array[i + 1]);
                strcpy(array[i + 1], temp);
                isSorted = false;
            }
        }
    }

    // Display the output
    printf("\nSorted strings:\n\n");
    for (int i = 0; i < stringNum; i++) {
        printf("%s\n", array[i]);
    }
}