/*
  CH-230-A
  a6_p3.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MID_RANGE(a,b) ((float)(a + b)/2)

int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int min = MIN(MIN(a,b),c);
    int max = MAX(MAX(a,b),c);
    float MidRange = MID_RANGE(min,max);
    printf("The mid-range is: %.6f", MidRange);
    printf("\n");
    return 0;
}