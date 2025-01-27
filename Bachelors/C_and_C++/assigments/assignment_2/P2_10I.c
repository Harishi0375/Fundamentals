/*
  CH-230-A
  a2.p10.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int n,p;
    p = 1;
    printf("enter a value: ");
    scanf("%d",&n);
    while (n <= 0)
    {
        printf("enter a value: ");
        scanf("%d",&n);
    }
    printf("1 day = 24 hours\n");
    while (p != n)
    {
        p = p + 1;
        printf("%d days = %d hours\n",p,p*24);
    }
    return 0;
}