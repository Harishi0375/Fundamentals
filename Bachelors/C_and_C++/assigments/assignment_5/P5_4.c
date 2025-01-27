/*
  CH-230-A
  a5_p4.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void divby5(float arr[], int size); 

int main()
{
    int n;
    float *arr;
    scanf("%d",&n);
    if (n == 0)
    {
        printf("program terminated"); //if n was 0
        return 0;
    }
    
    arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&arr[i]); //function input
    }
    printf("Before:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.3f ",arr[i]);
    }
    printf("\n");
    printf("After:\n");
    divby5(arr, n); //function call
    free(arr); //free allocated memory
    return 0;
}

void divby5(float arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i]/5.0; // divide by 5
    }
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ",arr[i]);
    }  
}

