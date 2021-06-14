#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printFile(FILE*);

int main()
{
    // Declare variables
    FILE* pfin = NULL;
    FILE* pfout = NULL;
    const char* filepath = "./files/for_exercise.txt";
    int c; // For storing temporary character

    // Open the files (for reading and writing)
    pfin = fopen(filepath, "r");
    pfout = fopen("./temp.txt", "w+");
    if ((pfin == NULL) || (pfout == NULL)) {
        printf("Fail to open the files. Please check.\n");
    }

    // Read the characters
    while ((c = fgetc(pfin)) != EOF) {
        // If the character is lowercase, convert it to uppercase and write to the new file
        fputc(islower(c) ? c - 32 : c, pfout);
    }
    
    // Close the file for reading
    fclose(pfin);
    pfin = NULL;

    // Move the position to the beginning of the file
    rewind(pfout);

    // Display the newfile
    printFile(pfout);

    // Close the new file
    fclose(pfout);
    pfout = NULL;

    // If the result is okay, remove the original file and rename the temp file to the original one
    char isCorrect;
    
    printf("\nIs the conversion correct? (y/n)");
    scanf("%c", &isCorrect);

    if (isCorrect == 'y') {
        remove(filepath);
        rename("./temp.txt", filepath);
    }
    else {
        remove("./temp.txt");
    }

    return 0;
}

void printFile(FILE* pfile)
{
    int c;

    while ((c = fgetc(pfile)) != EOF) {
        printf("%c", c);
    }
}