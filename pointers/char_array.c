#include <stdio.h>

void copyString(char* to, const char* from);
int countString(const char* lptr);

int main()
{
    // Declaration
    char s1[100];
    char s2[] = "Hello, world!";

    copyString(s1, s2);

    // Display
    printf("s1: %s\n", s1);
    printf("The length of s1: %d\n", countString(s1));
    printf("The length of \'Applepie\': %d\n", countString("Applepie"));
    printf("The length of \'\': %d\n", countString(""));

    return 0;
}

void copyString(char* to, const char* from)
{
    while (*from)
        *to++ = *from++;
}

int countString(const char* lptr)
{
    const char* rptr = lptr;

    while (*rptr)
        rptr++;

    return rptr - lptr;
}