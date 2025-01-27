//  Sum of the First n Natural Numbers

#include <stdio.h>

int main()
{
    int idx,n,sum = 0;
    printf("enter a positive number: ");
    scanf("%d",&n);
    idx = 1;
    for (idx = 1; idx <= n; idx++)
    {
        printf("processing %d..\n",idx);
        sum += idx;
    }
    
    printf("the sum is %d\n",sum);
    return 0;
}