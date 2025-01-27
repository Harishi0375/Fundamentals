/*
  CH-230-A
  a2.p8.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int value;
    scanf("%d",&value);
    if (value%2 == 0 && value%7 == 0)
    {
        printf("The number is divisible by 2 and 7\n");
    }
    else
    {
      printf("The number is NOT divisible by 2 and 7\n");  
    }
    return 0;

}       