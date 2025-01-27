/*
  CH-230-A
  a2_p3.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/


#include <stdio.h>

int main()
{
    int weeks,days,hours,total;
    printf("enter weeks:");
    scanf("%d",&weeks);
    printf("enter days:");
    scanf("%d",&days);
    printf("enter hours:");
    scanf("%d",&hours);
    
    total = (weeks * 168) + (days * 24) + hours;
    printf("the total hours: %d\n",total);

    return 0;
}