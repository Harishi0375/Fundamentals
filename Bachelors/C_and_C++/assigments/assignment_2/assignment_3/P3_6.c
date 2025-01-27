/*
  CH-230-A
  a3_p6.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

float to_pounds(int kg, int g); //function declaration

int main()
{
    int kg,g;
    float total;
    scanf("%d",&kg);
    scanf("%d",&g);
    total = to_pounds(kg,g);
    printf("Result of conversion: %f\n", total);
    return 0;
}

float to_pounds(int kg, int g)
{
    float sum;
    sum = (kg * 2.2) + ((g/1000.0) * 2.2); //conversion
    return sum;
}