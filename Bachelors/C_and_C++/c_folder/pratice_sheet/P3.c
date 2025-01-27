#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);
    
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    FILE *fptr;
    fptr = fopen("squares.txt","w");
    if (fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    for (int i = n-1; i >= 0; i--)
    {
        fprintf(fptr,"%d  %d\n",arr[i],arr[i]*arr[i]);
    }

    fclose(fptr);
    free(arr);

    return 0;    
}