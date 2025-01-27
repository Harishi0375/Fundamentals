/*
  CH-230-A
  a5_p6.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; // number of elements
    scanf("%d",&n);
    float *arr = (float*)malloc(n * sizeof(float)); // dynamic memory allocation
    if (arr == NULL)
    {
        printf("EMPTY ARRAY\n");
        return EXIT_FAILURE; //exit notifying as failure
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    int count = 0;
    float *ptr = arr;
    while (*ptr >= 0) //pointer arithmetic
    {
        ++count;
        ++ptr; 
    }
    
    printf("Before the first negative value: %d",count);
    free(arr);

    return 0;
}
