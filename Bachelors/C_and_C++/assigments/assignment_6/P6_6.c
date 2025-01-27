/*
  CH-230-A
  a6_p6.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    unsigned char c;
    scanf(" %c",&c);
    int ascii = (int)c;
    printf("The decimal representation is: %d\n", ascii); //decimal representation

    printf("The binary representation is: ");
    int size = sizeof(c) * 8;
    for (int i = size - 1; i >= 0; i--) //right shift the ch by i bits
    {
        int bit = (c >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}