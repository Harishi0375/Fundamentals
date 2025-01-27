/*
  CH-230-A
  a4_p2.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char string[50];
    fgets(string, sizeof(string), stdin); // Read a line of text using fgets
    const int length = strlen(string) -1 ; // Calculate the length of the string
    
    int count = 0;
    for (int i = 0; i < length; ++i) 
    {
        // Exclude newline and space characters
        if (string[i] == '\n' && string[i] == ' ')
        {
            continue; 
        }
        // no space infront
        if(count == 0)
        {
            printf("%c\n", string[i]);
            count++;
        }
        // space infront
        else if(count == 1)
        {
            printf(" %c\n", string[i]);
            count = 0;
        }
    }
    
    return 0;
}
