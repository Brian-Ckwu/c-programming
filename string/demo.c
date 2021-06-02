#include <stdio.h>
#include <string.h>

void helloWorld(void);

int main()
{
    // String functions
    // helloWorld();
    char inputStr[10];

    printf("Please enter a string: ");
    scanf("%s", inputStr);

    printf("%s %zu", inputStr, strlen(inputStr));

    return 0;
}

void helloWorld(void)
{
    // Create a character string
    char msg[] = "Hello, world!";
    // Display the message
    printf("%s <-- %zu characters in total", msg, strlen(msg));
}

