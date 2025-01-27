/*
CH-230-A
a7_p4.c
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printuppercase(char *str)
{
    while (*str)
    {
        printf("%c", toupper(*str));
        str++;
    }
    printf("\n");
}

void printlowercase(char *str)
{
    while (*str)
    {
        printf("%c", tolower(*str));
        str++;
    }
    printf("\n");
}

void changecase(char *str)
{
    while (*str)
    {
        if (islower(*str))
        {
            printf("%c", toupper(*str));
        }
        else if (isupper(*str))
        {
            printf("%c", tolower(*str));
        }
        else
        {
            printf("%c", *str);
        }
        str++;  
    }
    printf("\n"); 
}

int main()
{
    char c[100];
    void (*functions[])(char*) = {printuppercase,printlowercase,changecase};

    fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n")] = '\0'; //Remove the newline character from the input

    while (1)
    {
        char num;
        scanf(" %c",&num);
        
        if (num >= '1' && num <= '3')
        {
            functions[num - '1'](c);
        }
        else
        {
            break;
        } 
    }
    return 0;
}