/*
  CH-230-A
  a3_p11.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/


#include <stdio.h>
#include <string.h>

int main()
{
    char one[100],two[100];
    int Length1,Length2;
    char c;
    fgets(one, sizeof(one), stdin); //fgets is much more reliable to read spaces in strings
    fgets(two, sizeof(two), stdin); 
    scanf(" %c",&c);
    
    Length1 = strlen(one) - 1; //function for string length
    printf("length1=%d\n",Length1);
    Length2 = strlen(two) - 1; //function for string length
    printf("length2=%d\n",Length2);

    one[strcspn(one, "\n")] = '\0';
    two[strcspn(two, "\n")] = '\0';
    
    char concatenation[200] = "";
    strcat(concatenation, one); 
    strcat(concatenation, two);
    printf("concatenation=%s\n",concatenation);

    char copy[100];
    strcpy(copy,two);
    printf("copy=%s\n",copy);

    if (Length1 > Length2)
    {
       printf("one is smaller than two\n");
    }
    else if (Length1 < Length2)
    {
        printf("two is smaller than one\n"); 
    }
    else
    {
        printf("one is equal to two\n");
    }


    int found = 0;
    for (int i = 0; i <= Length2; i++)
    {
        if (two[i] == c)
        {
            printf("position=%d\n",i);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("the character is not in the string\n");
    }
    return 0;
}