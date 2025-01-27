/*
  CH-230-A
  a4_p10.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>

void proddivpowinv(float a,float b,float *prod, float *div, float *pwr, float *invb);

int main()
{
    float a,b,p,d,pp,i; //(p) power, (d) division, (pp) power, (i) inverse
    printf("enter value for a: ");
    scanf("%f",&a);
    printf("enter value for b: ");
    scanf("%f",&b);

    proddivpowinv(a,b,&p,&d,&pp,&i);
    printf("product=%f\n",p);
    printf("division=%f\n",d);
    printf("power=%f\n",pp);
    printf("inverse=%f\n",i);
    return 0;
}

void proddivpowinv(float a,float b,float *prod, float *div, float *pwr, float *invb)
{
    *prod = a*b; //product
    *div = a/b; //division
    *pwr = pow(a,b); //a^b
    *invb = 1/b; //inverse
}