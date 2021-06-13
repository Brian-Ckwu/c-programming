#include <stdio.h>
#include <stdlib.h>

int countFileLines(FILE* pfile);

int main()
{
    // Declare variables
    FILE* pfile = NULL;
    char filename[20] = "./files/results.txt";
    int lines = 0;

    // Open the file
    pfile = fopen(filename, "r");

    if (pfile == NULL) {
        printf("Fail to open file %s. Please check.\n", filename);
        return -1;
    }

    // Count lines
    lines = countFileLines(pfile);

    // Remember to close the file
    fclose(pfile); // Return 0 if successful
    pfile = NULL;
    
    // Display line count
    printf("There are %d lines in the file %s.", lines, filename);

    return 0;
}

int countFileLines(FILE* pfile)
{
    // Declare variables
    int lines = 1;
    char temp;
    const char kNEWLINE = '\n';

    while ((temp = fgetc(pfile)) != EOF) {
        if (temp == kNEWLINE) {
            lines++;
        }
        // Below is also okay
        // lines += (temp == kNEWLINE) ? 1 : 0;
    }

    return lines;
}