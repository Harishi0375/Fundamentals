#include <stdio.h>

int main()
{
    int a = 2,b,c;
    float f1 = 1.34;
    printf("f1 = %f,\n",f1);
    float f2 = 3.56;
    printf("f2 = %f,\n",f2);
    char ch = 'D';
    printf("ch = %c,\n",ch);
    b = f1 >= f2;
    printf("b = %d,\n",b);
    c = !b;
    printf("c = %d,\n",c);
    b = c==b;
    printf("b = %d,\n",b);
    b = b != c;
    printf("b = %d,\n",b);
    c = f2 > a;
    printf("c = %d,\n",c);
    c = ch > a;
    printf("c = %d,\n",c);
    return 0;
}