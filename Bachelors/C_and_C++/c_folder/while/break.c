#include <stdio.h>

int main()
{
    int num, i = 0;
    scanf("%d",&num);
    while (i < 50)
    {
        printf("%d\n",i);
        i++;
        if (i == num)
        {
            break;
        }
        
    }
    return 0;
}