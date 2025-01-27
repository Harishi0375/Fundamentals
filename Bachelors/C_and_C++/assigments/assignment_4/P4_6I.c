/*
  CH-230-A
  a4_p6.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int twogreatest(int *array, int n);

int main()
{
    int n; //number of integers to be added in array
    int *array;
    printf("enter number of integers: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int)); //dynamically allocationg memory for the array

    printf("enter %d integer(s):\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    twogreatest(array,n);
}

int twogreatest(int *array,int size)
{
    int max1 = array[0];
    int max2 = array[1];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max1)
        {   
            //to ensure duplicate values are not considered
            if (max1 == array[i])
            {
                continue;
            }
            max2 = max1;
            max1 = array[i];
        }
        else if (array[i] > max2)
        {
            max2 = array[i];
        }    
    }
    printf("The first greatest value: %d\n", max1);
    printf("The second greatest value: %d\n", max2); 

    free(array); //deallocating
    return 0;
}