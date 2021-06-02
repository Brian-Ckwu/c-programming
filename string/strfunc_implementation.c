// Implementation of functions similar to strlen(), strcat(), and strcmp()

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int myStrlen(const char str[]);
void myStrcat(char result[], const char str1[], const char str2[]);
bool myStrcmp(const char str1[], const char str2[]);

int main()
{
    // Test myStrlen()
    const char s[20] = "Hello, world!";

    printf("The string size from sizeof(): %zu\n", sizeof(s));
    printf("The string length from strlen(): %zu\n", strlen(s));
    printf("The string length from myStrlen(): %zu\n", myStrlen(s));

    // Test myStrcat()
    char result[90];
    const char s1[] = "Jason";
    const char s2[] = "Market";

    myStrcat(result, s1, s2);
    printf("The concatenation result: %s\n", result);

    // Test myStrcmp()
    const char s3[] = "helloo";
    const char s4[] = "hello";
    const char s5[] = "hello";
    const char s6[] = "heloo";

    printf("%s is %s to %s\n", s5, myStrcmp(s5, s6) ? "equal" : "not equal", s6);

    return 0;
}

int myStrlen(const char str[])
{
    int len = 0;
    
    // Implementation 1
    // int i = 0; // This variable is not necessary
    // while (str[len] != '\0') {
    //     len++;
    //     i++; // This variable is not necessary
    // }

    // Implementation 2
    for (int i = 0; str[i] != '\0'; i++)
        len++;

    return len;
}

void myStrcat(char result[], const char str1[], const char str2[])
{
    // Variable for recording the current index to append character in the result character array
    int loc = 0;

    // Loop through str1 and append the characters
    for (int i = 0; str1[i] != '\0'; i++) {
        result[loc] = str1[i];
        loc++;
    }

    // Loop through str2 and append the characters
    for (int i = 0; str2[i] != '\0'; i++) {
        result[loc] = str2[i];
        loc++;
    }
}

bool myStrcmp(const char str1[], const char str2[])
{
    // Initialize the result to true
    bool isEqual = true;

    // If the lengths of the two strings are different, set the isEqual to false
    if (myStrlen(str1) != myStrlen(str2)){
        isEqual = false;
    }
    // Loop through str1. If the characters are different, set the isEqual to false and break the loop
    else {
        for (int i = 0; str1[i] != '\0'; i++) {
            if (str1[i] != str2[i]) {
                isEqual = false;
                break;
            }
        }
    }

    return isEqual;
}