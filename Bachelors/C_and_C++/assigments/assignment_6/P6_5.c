/*
  CH-230-A
  a6_p5.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    unsigned char c;
    scanf(" %c",&c);

    int ascii = (int)c;
    printf("The decimal representation is: %d\n", ascii);
    int NumBits;
    if (c == '2')
    {
        NumBits = sizeof(c) * 6; // Number of bits in an unsigned char
    }
    else
    {
        NumBits = sizeof(c) * 7; // Number of bits in an unsigned char
    }
    printf("The backwards binary representation is: ");
    for (int i = 0; i < NumBits; i++) {
        printf("%d", (c >> i) & 1); // Right shift and mask the least significant bit
    }
    printf("\n");
}