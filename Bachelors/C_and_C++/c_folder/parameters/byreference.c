#include <stdio.h>
//by reference
void increase(int *par)
{
    *par = *par + 1;
}

int main()
{
    int number = 5;
    increase(&number);
    printf("new num=%d",number);
    return 0;
}