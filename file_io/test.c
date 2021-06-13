#include <stdio.h>
#include <stdbool.h>

int main()
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

    return 0;
}