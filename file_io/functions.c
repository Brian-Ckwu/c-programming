/*
    Some common functions related to file manipulation
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void accessFiles(void);
void readFromFiles(void);
void writeToFiles(void);
int positionInFiles(void);

int main()
{
    int status = 0;
    // accessFiles();
    // readFromFiles();
    status = positionInFiles();

    return status;
}

// fopen(), fclose(), rename(), remove()
void accessFiles(void)
{
    // Some variables
    int result;
    FILE* pfile = NULL;
    char* filename = "./files/demofile.txt";

    // 1. fopen()
    pfile = fopen(filename, "w"); // Parameters: 1. Char pointer to the filename 2. Mode / Return value: FILE pointer (NULL if not successful)
    
    if (pfile == NULL) { // If the file is not opened successfully
        printf("The file %s is not opened successfully.\n", filename);
    }
    else {
        printf("The address of the FILE object is at %p.\n", pfile);
    }

    // 2. fclose()
    result = fclose(pfile); // Return value: 0 if successful / EOF if not
    pfile = NULL; // Set the FILE pointer to NULL (good practice)

    // The following functions should not be used if the file is in use
    // 3. Rename
    char* newFilename = "./files/new_demofile.txt";
    result = rename(filename, newFilename); // Return value: 0 if successful / nonzero otherwise
    if (result == 0) {
        printf("The file %s is renamed to %s.\n", filename, newFilename);
    }
    else {
        printf("Fail to rename the file %s.\n", filename);
    }

    // 4. Remove
    result = remove(newFilename);

    if (result) {
        printf("The file %s is not removed due to some reasons.\n", newFilename);
    }
    else {
        printf("The file %s has been removed.\n", newFilename);
    }
}

// fgetc(), fgets(), and fscanf()
void readFromFiles(void)
{
    // Some variables
    FILE* pfile = NULL;
    const char* filename = "./files/results.txt";

    // Open the file
    pfile = fopen(filename, "r");
    if (pfile == NULL) { // Always check if the file is opened successfully
        exit(-1);
    }

    // 1. fgetc()
    int c;
    while ((c = fgetc(pfile)) != EOF) { // Return value of fgetc(): the ASCII number (int) of the character
        printf("%c", c); // Format to character
    }

    rewind(pfile); // Set at the beginning of the file
    sleep(3);

    // 2. fgets(): Parameters: 1. Char pointer 2. Number of characteres (including '\0') 3. FILE pointer / Return value: Char pointer or NULL (if EOF)
    const int readSize = 100;
    char temp[readSize];

    while (fgets(temp, readSize, pfile) != NULL) { // Read (readSize - 1) characters at a time
        printf("%s", temp);
    }

    fclose(pfile);
    pfile = NULL;

    // 3. fscanf(): Parameters: 1. FILE pointer 2. Char pointer (the format) 3. The addresses
    const char* filename_2 = "./files/input.txt";
    pfile = fopen(filename_2, "r");

    if (pfile == NULL) {
        exit(-1);
    }

    char itemName[20];
    float price = 0.0;
    int quantity = 0;

    fscanf(pfile, "%s %f %d", itemName, &price, &quantity);

    printf("\nThe information of the item: %s %f %d", itemName, price, quantity);
}

// fputc(), fputs(), and fprintf()
void writeToFiles(void)
{
    // 1. int fputc(int ch, FILE* pfile) -> written char / EOF if failure
    // 2. int fputs(const char* str, FILE* pfile)
    // 3. int fprintf(FILE* stream, const char* format, ...) -> number of written characters
}

// ftell() & fseek()
int positionInFiles(void)
{
    // Declaration
    const char* kFilename = "./files/test_positions.txt";
    const char* kSomeText = "Here is some text.\n";
    FILE* pfile = NULL;
    char temp;
    long pos;

    // Open the file
    pfile = fopen(kFilename, "w+");

    if (pfile == NULL) {
        printf("Fail to open the file.\n");
        return -1;
    }

    // Write some text
    fputs(kSomeText, pfile);

    // Rewind to the beginning
    rewind(pfile);

    // 1. long ftell(FILE* pfile) -> position
    do {
        pos = ftell(pfile);
        temp = fgetc(pfile);
        printf("%ld -> %d\n", pos, temp);
    }
    while (temp != EOF);

    // Close the file
    fclose(pfile);
    pfile = NULL;

    return 0;
}