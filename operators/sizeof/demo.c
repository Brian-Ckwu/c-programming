#include <stdio.h>

void main()
{
    printf("bool: %zd", sizeof(_Bool));
    printf("char: %zd\n", sizeof(char));
    printf("short int: %zd\n", sizeof(short int));
    printf("int: %zd\n", sizeof(int));
    printf("unsigned int: %zd\n", sizeof(unsigned int));
    printf("long: %zd\n", sizeof(long));
    printf("unsigned: %zd\n", sizeof(unsigned));
    printf("long long: %zd\n", sizeof(long long));
    printf("float: %zd\n", sizeof(float));
    printf("double: %zd\n", sizeof(double));
    printf("long double: %zd", sizeof(long double));
}