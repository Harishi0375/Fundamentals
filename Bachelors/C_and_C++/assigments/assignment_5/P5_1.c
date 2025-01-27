/*
  CH-230-A
  a5_p1.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int n;
    char ch;
    scanf("%d", &n);
    scanf(" %c", &ch);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
        
    }
    return 0;
}