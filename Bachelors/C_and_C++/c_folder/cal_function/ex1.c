#include <math.h>
#include <stdio.h>

int main()
{
    double number,root;
    scanf("%lf",&number);
    if (number >= 0)
    {
        root = sqrt(number);  //calling function
        printf("Square root is %f\n",root);
    }
    else
    {
        printf("cannot calc square root\n");
    }
    return 0;
}
