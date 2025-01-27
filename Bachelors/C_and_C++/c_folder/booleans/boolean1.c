#include <stdio.h>

int main()
{
    int a,b,c;
    a = 0;
    printf("the value of a now is: %d\n",a);
    b = 1;
    printf("the value of b now is: %d\n",b);
    c = a || b;
    printf("the value of c now is: %d\n",c);
    c = a && b;
    printf("the value of c now is: %d\n",c);
    a = !a;
    printf("the value of a now is: %d\n",a);
    c = a && b;
    printf("the value of c now is: %d\n",c);
    c = (a && !b) && (a || b);
    printf("the value of c now is: %d\n",c);
    return 0;

}