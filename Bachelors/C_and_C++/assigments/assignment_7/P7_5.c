/*
CH-230-A
a7_p5.c
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int ascending(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int descending(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

int main()
{
    int n;
    int *arr;

    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int) * n); 
    if (arr == NULL)
    {
        exit(1);
    }
    for ( int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1) //infinite loop
    {
        char letter;
        scanf(" %c",&letter);
        if (letter == 'a')
        {
            qsort(arr,n,sizeof(int),ascending); //using qsort function for ascending
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");  
        }
        else if (letter == 'd')
        {
            qsort(arr,n,sizeof(int),descending); //using qsort function for descending
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (letter == 'e')
        {
            break;
        }    
    }
    free(arr);
}