#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaration
    const char* kFilename = "./files/test_positions.txt";
    FILE* pfile = NULL;
    long pos = -1;

    // Open the file
    pfile = fopen(kFilename, "r");

    if (pfile == NULL) {
        printf("Fail to open the file.\n");
        return -1;
    }

    // Set the position to the end of the file
    do {
        fseek(pfile, pos, SEEK_END);
        printf("%c", fgetc(pfile));
        pos--;
    } while (ftell(pfile) - 1 > 0);

    // Close the file
    fclose(pfile);
    pfile = NULL;

    return 0;
}