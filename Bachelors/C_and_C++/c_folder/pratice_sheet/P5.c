#include <stdio.h>
#include <stdbool.h>


bool odd(unsigned char data)
{
    if ((data & 1) != 0)
    {
        return true;
    }
    return false;
}

int main()
{
    unsigned char n;
    scanf("%c",&n);
    if (odd(n) == true)
    {
        printf("true\n");
        return 0;
    }
    printf("false\n");
    return 0;
}