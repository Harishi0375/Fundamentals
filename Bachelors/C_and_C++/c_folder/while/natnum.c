//  Sum of the First n Natural Numbers

#include <stdio.h>

int main()
{
    int idx,n,sum = 0;
    printf("enter a positive number: ");
    scanf("%d",&n);
    idx = 1;
    while (idx <= n)
    {
        sum += idx;
        idx++;
    }
    printf("the sum is %d\n",sum);
    return 0;
}


