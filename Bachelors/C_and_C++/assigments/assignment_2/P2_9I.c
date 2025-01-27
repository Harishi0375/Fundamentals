/*
  CH-230-A
  a2.p9.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    char value;
    scanf("%c",&value);

    if (isalpha(value))
    {
        printf("%c is a letter\n",value);
    }
    else if (isdigit(value))
    {
        printf("%c is a digit\n",value);
    }
    else
    {
        printf("%c is some other symbol\n",value);
    }
    return 0;
}