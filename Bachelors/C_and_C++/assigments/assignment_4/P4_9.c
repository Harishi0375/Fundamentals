/*
  CH-230-A
  a4_p9.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

int prodminmax(int arr[], int n)
{
    int max = arr[0]; //define max
    int min = arr[0]; //define min
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }    
    }
    printf("max value in list: %d\n",max);
    printf("min value in list: %d\n",min);
    return max * min;
}

int main()
{
    int n; //number of integers to be added in array
    int *arr;
    printf("enter number of integers: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int)); //allocation
    
    printf("enter %d integer(s):\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    prodminmax(arr,n);
    free(arr); //deallocation
}