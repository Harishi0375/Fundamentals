/*
  CH-230-A
  a6_p7.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

void set3bits(unsigned char ch,int a, int b, int c);
int main()
{
    unsigned char ch;
    int a;
    int b;
    int c;
    scanf(" %c",&ch);
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int ascii = (int)ch;
    printf("The decimal representation is: %d\n", ascii); //decimal representation

    printf("The binary representation is: ");
    int size = sizeof(ch) * 8;
    for (int i = size - 1; i >= 0; i--) //right shift the ch by i bits
    {
        int bit = (ch >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");

    set3bits(ch,a,b,c);
}

void set3bits(unsigned char ch,int a, int b, int c)
{
    ch |= (1 << a) | (1 << b) | (1 << c);
    int size = sizeof(ch) * 8;
    printf("After setting the bits: ");
    for (int i = size - 1; i >= 0; i--) //right shift the ch by i bits
    {
        int bit = (ch >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}
