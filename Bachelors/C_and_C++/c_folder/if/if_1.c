#include <stdio.h>

int main()
{
    int first,second;
    printf("type the first number: \n");
    scanf("%d",&first);
    printf("type the second number: \n");
    scanf("%d",&second);
    if(first > second)
    {
        printf("first number is the largest \n");
    }
    else if (first == second)
    {
        printf("both numbers are equal \n"); 
    }
    else
    {
        printf("second number is the largest \n");
    }
}   