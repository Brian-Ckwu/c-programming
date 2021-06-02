#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    
    int l, i;

    printf("\n\nPrint individual characters of string in reverse order: \n\n");
    printf("Input the string: ");
    scanf("%s", str);

    l = strlen(str);
    for (i = l - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}