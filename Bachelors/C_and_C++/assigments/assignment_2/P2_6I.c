/*
  CH-230-A
  a2_p6.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
   int x,y;
   printf("enter value for x:");
   scanf("%d",&x);
   printf("enter value for y:");
   scanf("%d",&y);
   int *prt_one,*prt_two,*prt_three;
   prt_one = &x;
   prt_two = &x;
   prt_three = &y;
   printf("value of prt_one: %p\n",prt_one);
   printf("value of prt_two: %p\n",prt_two);
   printf("value of prt_three: %p\n",prt_three);
   return 0;
}