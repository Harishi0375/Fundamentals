#include <stdio.h>

int main()
{
    int c;
    for (c = 0; c < 3; c++)
    {
        switch (c)
        {
        case 1:
            printf("here is 1\n"); 
            break;
        case 2:
            printf("here is 2\n");
        case 3:
            printf("here is 3\n");
            break;
        default:
            printf("here is default\n");
            break;
            
        }
    }
    return 0;
}
