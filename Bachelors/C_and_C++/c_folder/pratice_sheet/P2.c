#include <stdio.h>

int main()
{
    double d;
    float f;
    int n;

    scanf("%lf",&d);
    scanf("%f",&f);
    scanf("%d",&n);

    double result = d*f*n;

    printf("first value of result: %lf\n",result);

    double *r_ptr = &result;
    // double *r_ptr;
    // *r_ptr = &result;
    
    *r_ptr = *r_ptr + 5;
    printf("value of pointer: %lf\n",result);
    printf("value of result: %lf\n",*r_ptr);

    return 0;

}