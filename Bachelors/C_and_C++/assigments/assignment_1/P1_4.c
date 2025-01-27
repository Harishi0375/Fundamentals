#include <stdio.h>

int main()
{
    int sum,product,difference,x,y;
    float division;
    int remainder;
    x = 17;
    y = 4;
    sum = x + y;
    printf("the sum is: %d\n",sum);
    product = x * y;
    printf("the product is: %d\n",product);
    difference = x - y;
    printf("the difference is: %d\n",difference);

    division = (float)x/(float)y;
    printf("the division is: %f\n",division);

    remainder = x%y;
    printf("the remainder is: %d\n",remainder);

}