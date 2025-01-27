/*
  CH-230-A
  a6_p4.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int dim;
    int scalar_product = 0;
    scanf("%d",&dim); //dimension
    int x[dim],y[dim]; //vectors
    for (int i = 0; i < dim; i++)
    {
        scanf("%d",&x[i]); //vector value of x
    }
    for (int i = 0; i < dim; i++)
    {
        scanf("%d",&y[i]); //vector value of y
    }
#ifdef INTERMEDIATE //print if intermediate is defined
    printf("The intermediate product values are:\n");
#endif  
    for (int i = 0; i < dim; i++)
    {
        int temp = x[i] * y[i];
        scalar_product += temp;
    #ifdef INTERMEDIATE //print if intermediate is defined
        printf("%d\n",temp);
    #endif 
    }
    printf("The scalar product is: %d",scalar_product);
    return 0;
}

