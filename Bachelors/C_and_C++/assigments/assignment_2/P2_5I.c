/*
  CH-230-A
  a2_p5.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int a;
    printf("enter a value:");
    scanf("%d",&a);
    printf("the value you have entered is: %d\n",a);
    int *ptr_a;
    ptr_a = &a;
    printf("the address of a: %p\n",ptr_a);
    *ptr_a += 5; // a = a + 5 
    printf("the value of a: %d\n",*ptr_a);
    printf("the address of a after: %p\n",ptr_a);
    return 0;
}