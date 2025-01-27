/*
  CH-230-A
  a3_p5.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    char c;
    int n,value;
    double temp[100];
    printf("enter a character:"); //either 's'/'p'/'t' or other
    scanf("%c",&c);

    printf("enter a number:"); //number of temperature inputs
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        printf("input temperature in C:");
        scanf("%d",&value);
        temp[i-1] = value;  // because i = 1 and array's start from 0 
    }
    
    double sum = 0;
    double f;
    double avg;
    switch (c)
    {
    case 's': // sum
        for (int i = 0; i <= n; i++)
        {
            sum = sum + temp[i];
        }
        printf("the sum is:%lf",sum);
        break;
    
    case 'p': //list in C
        printf("the list of temperatures:\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%lf\n",temp[i-1]);  // because i = 1 and array's start from 0
        }
        break;

    case 't': //list in F
        printf("the list of temperatures in fahrenheit:\n");
        for (int i = 1; i <= n; i++)
        {
            f = (1.8 * temp[i-1]) + 32; // because i = 1 and array's start from 0
            printf("%lf\n",f);
        }
        break;
    
    default: // mean in C
        for (int i = 1; i <= n; i++)
        {
            sum = sum + temp[i-1]; // because i = 1 and array's start from 0
            avg = sum/n;
        }
        printf("the mean is:%lf",avg);
        break;
    }
    
}