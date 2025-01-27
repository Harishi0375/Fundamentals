/*
  CH-230-A
  a4_p1.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <math.h>


int main() 
{
    double lowlimit, uplimit, stepsize;
    scanf("%lf", &lowlimit);
    scanf("%lf", &uplimit);
    scanf("%lf", &stepsize);

    double area, perimeter;
    for (double i = lowlimit; i <= uplimit; i = i + stepsize) {
        area = M_PI * i * i;  //why does M_PI not work
        perimeter = 2.000000 * M_PI * i;
        printf("%f %f %f\n", i, area, perimeter);
    }
    return 0;
}




