/*
  CH-230-A
  a5_p2.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

void divby5(float arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i]/5.0; //divides by 5 
    }
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ",arr[i]);
    }  
}

int main()
{
    float arr[6] = {5.5,6.5,7.75,8,9.6,10.36};
    int n =  6;
    printf("Before:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.3f ",arr[i]); //printing before
    }
    printf("\n");
    printf("After:\n");
    divby5(arr,n); //inside function print statement is present
    printf("\n");
    return 0;
}