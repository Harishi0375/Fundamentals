/*
  CH-230-A
  a5_p3.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>

int count_lower(char* str); //str is a pointer to character

int count_lower(char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        if (islower(*str))
        {
            count = count + 1; //no. of lowercase characters
        }
        str = str + 1;
        
    }
    return count;
}

int main()
{
    char str[51]; //51 for '\0' as last character
    while (1)
    {
        printf("Enter the string:\n");
        fgets(str,sizeof(str),stdin);

        if (str[0] == '\n')
        {
            break; //exit the loop incase no characters
        }
        
        int count = count_lower(str); //using same variable name because I cant think another one :D
        printf("The number of lowercase characters are: %d\n",count);
    }
    return 0;
}

