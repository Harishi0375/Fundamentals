/*
  CH-230-A
  a3_p8.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
int length; //global
float array[10]; //global

float sum_function(float array[]); //function declaration
float avg_function(float array[]); //function declaration


int main()
{
    for (int i = 0; i <= 9; i++) //should have used while but for preffered for loop
    {
        printf("enter a float: ");
        scanf("%f",&array[i]);
        if (array[0] == -99.0)
        {
            printf("the sum is = 0\n");
            printf("the average is = 0\n");
            break; //inside for loop hence used break
        }
        else if (array[i] == -99.0) //sum and avg only printed when -99.0 entered
        {
            length = i - 1;
            printf("the sum is = %f\n",sum_function(array)); //calling function
            printf("the average is = %f\n",avg_function(array)); //calling function
            break;
        }
        
        
    }
    
}

float sum_function(float array[])
{
    float sum = 0.0;
    for (int i = 0; i <= length; i++)
    {
        sum = sum + array[i];
    }
    return sum;
    
}

float avg_function(float array[])
{
    float avg = 0.0;
    float sum = sum_function(array);
    avg = sum/(length+1);
    return avg;
}

