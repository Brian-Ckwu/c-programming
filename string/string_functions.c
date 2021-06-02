#include <stdio.h>
#include <string.h>

// Common functions
void demoStrLen(void);
void demoStrCpy(void);
void demoStrCat(void);
void demoStrCmp(void);

// Functions for searching a string
void demoStrChr(void);
void demoStrStr(void);

// Function for tokenizing a string
void demoStrTok(void);

// Functions for analyzing a string
void demoIsLower(void);
void demoIsUpper(void);
void demoIsAlpha(void);
void demoIsDigit(void);

// Functions for converting a string
void demoToUpper(void);
void demoToLower(void);
void demoStrToNum(void);

int main()
{
    demoStrCpy();
}

/*
    Demonstration of some string functions
*/

void demoStrLen(void)
{
    char s[] = "hello";
    size_t sLen = strlen(s);
    size_t sSize = sizeof(s);
    
    printf("String length: %zu\n", sLen);
    printf("String size: %zu", sSize);
}

void demoStrCpy(void)
{
    char s1[] = "hello";
    char s2[] = "hihihihihihihihihi";

    strncpy(s1, s2, sizeof(s1) - 1);
    printf("Result of strncpy: %s\n", s1);

    strcpy(s1, s2);
    printf("Result of strcpy: %s", s1);
}

// strcat() and strncat()

// strcmp() and strncmp()

// 
