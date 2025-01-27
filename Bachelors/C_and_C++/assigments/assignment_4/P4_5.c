/*
  CH-230-A
  a4_p5.c
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

    return 0;
}

int count_consonants(char str[]) 
{
    int count = 0;
    char *ptr = str; // Pointer to the beginning of the string

    for (int i = 0; i < fullLength; i++)
    {
        // skip non alphabets
        if(!isalpha(*ptr))
        {
            ++ptr; // Move the pointer to the next character in the string
            continue;
        }

        char c = tolower(*ptr);
        // skip if vowel characters
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            ++ptr; // Move the pointer to the next character in the string
            continue;
        }

        ++count;
        ++ptr; // Move the pointer to the next character in the string
    }

    return count;
}

