#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLENGTH 20

// Define the structure
struct Item
{
    char* itemName;
    int quantity;
    float price;
    float amount;
};

void readItem(struct Item*);
void printItem(struct Item*);

int main()
{
    // Declare variables
    struct Item myItem = 
    {
        NULL,
        0,
        0.0,
        0.0
    };
    struct Item* itemPtr = &myItem;

    // Read and print Item
    readItem(itemPtr);
    printItem(itemPtr);

    free(itemPtr->itemName);

    return 0;
}

void readItem(struct Item* itemPtr)
{
    // temp for storing string
    char temp[READLENGTH];

    // Get user input
    printf("Please enter the item (name quantity price): ");
    scanf("%s %d %f", temp, &(itemPtr->quantity), &(itemPtr->price));

    // Allocate memory for the char pointer
    itemPtr->itemName = (char*) calloc(strlen(temp) + 1, sizeof(char)); // Remember to cast the pointer type
    if (itemPtr->itemName == NULL) // Check if the memory has been allocated successfully
        exit(-1);
    // Assign and calculate values
    strcpy(itemPtr->itemName, temp);
    itemPtr->amount = (float) (itemPtr->quantity) * (itemPtr->price);
}

void printItem(struct Item* itemPtr)
{
    printf("\nItem details:\n\n");
    printf("  Name: %s\n", itemPtr->itemName);
    printf("  Quantity: %d\n", itemPtr->quantity);
    printf("  Price: %.2f\n", itemPtr->price);
    printf("  Amount: %.2f\n", itemPtr->amount);
}