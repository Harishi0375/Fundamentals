#include <stdio.h>

int main()
{
    int n;
    char ch;
    scanf("%d",&n);
    getchar();
    scanf("%c",&ch);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
    
}