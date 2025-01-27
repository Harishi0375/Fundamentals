/*
  CH-230-A
  a4_p7.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int arr[30][30];
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);   
        }
    }
    printf("The entered matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); 
    }
    printf("Under the main diagonal:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ",arr[i][j]);
        }     
    }
    printf("\n");
    return 0;
}