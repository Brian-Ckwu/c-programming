#include <stdio.h>

void main()
{
    // Declaring enum type and variables
    enum Company {GOOGLE=1, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
    enum Company company1 = XEROX, company2 = GOOGLE, company3 = EBAY;
    // Display the value of the companies
    printf("%d\n%d\n%d", company1, company2, company3);
}