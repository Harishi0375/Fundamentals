/*
  CH-230-A
  a4_p4.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_consonants(char str[]);

int fullLength;

int main()
{
    int stringlength = 1;    
    char str[100];
    while (stringlength > 0)
    {
        fgets(str, sizeof(str), stdin);
        stringlength = strlen(str) - 1;
        fullLength = stringlength; //initial string length
        if(stringlength == 0)
        {
            break;
        }
        for (int i = 0; i <= stringlength; i++)
        {
            if (str[i] == ' ')
            {
                stringlength = stringlength - 1;
            }
            
        }
        int consonants = count_consonants(str);
        printf("Number of consonants=%d\n",consonants);
        
    }
    
}

int count_consonants(char str[])
{
    int consonants;
    for (int i = 0; i <= fullLength; i++)
    {
        // skip non alphabets
        if(!isalpha(str[i]))
        {
            continue;
        }

        char c = tolower(str[i]);
        // skip if vowel characters
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            continue;
        }
        
        ++consonants;
    }
    return consonants;   
}

