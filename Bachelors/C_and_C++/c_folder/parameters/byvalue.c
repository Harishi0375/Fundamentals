#include <stdio.h>
// by value
void increase(int par)
{
    par++;
}

int main()
{
    int number = 5;
    increase(number);
    printf("new num=%d",number);
    return 0;
}