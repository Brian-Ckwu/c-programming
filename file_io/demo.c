#include <stdio.h>

void fileFunctions(void);
void printIntAsChar(void);
void printCharAsInt(void);

int main()
{
    printIntAsChar();
    printCharAsInt();

    return 0;
}

void fileFunctions(void)
{
    // Declaration
    FILE* pfile = NULL;
    char* name = "./files/myfile.txt";

    pfile = fopen(name, "w"); // If the file doesn't exist, it will not return NULL if the mode is "w" and the file is created successfully
    printf("%p\n", pfile);
    

    if (pfile == NULL)
        printf("The file %s does not exist.", name);
    else
        printf("The file %s exists.", name);
    
    fclose(pfile);

    remove(name);
}

void printIntAsChar(void)
{
    int i = 65, j = 97;

    printf("%c %c\n", i, j);
}

void printCharAsInt(void)
{
    char s1 = 'A', s2 = 'a', r = '\n';
    
    printf("%d %d %d\n", s1, s2, r);
}