/*
  CH-230-A
  a3_p10.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

float product(float a,float b)
{
    return a*b;
}

void productbyref(float a, float b,float *p)
{
    *p = a * b;
}

void modifybyref(float *a, float *b)
{
    *a = (*a) + 3;
    *b = (*b) + 11;
}

int main()
{
    float a,b;
    a = 10;
    printf("orginal value of a = %f\n",a); //value of a 
    b = 5;
    printf("orginal value of b = %f\n",b); //value of b
    float c = product(a,b);
    printf("orginal value of a = %f\n",a); // no change in a 
    printf("orginal value of b = %f\n",b); //no change in b
    printf("orginal value of c = %f\n",c); // product of a and b
    float d;
    productbyref(a,b,&d);
    printf("orginal value of d = %f\n",d);  //same effect
    modifybyref(&a,&b);
    printf("final value of a = %f\n",a); //modifies and changes the ORGINAL value of a
    printf("final value of b = %f\n",b); //modifies and changes the ORGINAL value of b
}