/*
  CH-230-A
  a3_p4.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int position(char str[], char c)
{
    int idx;
    /* loop until end of string*/
    for (idx = 0; (str[idx] = c) && (str[idx] != '\0'); ++idx)
    {
        /* do nothing */
    }
    return idx;
}

int main()
{
    char line[80];
    while (1)
    {
        printf("Enter string:");
        fgets(line, sizeof(line), stdin);
        printf("The first occurrence of 'g' is: %d\n", position(line,'g'));
    }
    return 0;
}