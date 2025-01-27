#include <stdio.h>

int main()
{
    char a_string[] = "this is a string\0";
    char *p;
    int count = 0;
    printf("the string: %s\n", a_string); //prints the string
    for (p = a_string; *p != '\0'; p++)
    {
        count++;
    }
    printf("the string has %d chars.\n",count); // number of characters in the string
    p--;
    printf("printing the reverse string: ");
    while (count > 0)
    {
        printf("%c", *p); //the reverse order of the string
        p--;
        count--;
    }
    printf("\n");
    return 0; 
}