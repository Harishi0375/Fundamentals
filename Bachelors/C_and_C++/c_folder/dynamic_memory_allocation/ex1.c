#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *dyn_array, how_many, i;
    printf("how many elements ");
    scanf("%d",&how_many);
    dyn_array = (int*) malloc(sizeof(int) * how_many);
    if (dyn_array == NULL)
    {
        exit(1);
    }
    for ( i = 0; i < how_many; i++)
    {
        printf("input num: ");
        scanf("%d", &dyn_array[i]);
    }
    free(dyn_array);
    return 0;   
}