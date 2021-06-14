#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void compareIntChar(void);
void testLowerCase(void);

int main()
{
    testLowerCase();

    return 0;
}

void compareIntChar(void)
{
    // Test if type int and type char can be compared
    // Declare
    int i = 10;
    char c = '\n';
    bool b = false;

    // Assign
    b = (i == (int) c);

    if (b) {
        printf("%d and %c are the same.\n", i, c);
    }
    else {
        printf("They are not the same.");
    }
}

void testLowerCase(void)
{
    // Declaration
    char* s = "abc02/&#d*e";
    char temp;

    for (int i = 0; i < strlen(s); i++) {
        temp = *(s + i);
        printf("%c is %s lowercase\n", temp, (islower(temp)) ? "" : "not");
    }
}