/*
  CH-230-A
  a6_p2.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

#define LEAST_BIT(num) ((num) & 1) //macro bitwise AND operation

int main()
{
  unsigned char input;
  printf("enter an unsigned char: ");
  scanf(" %c", &input);

  int ascii = (int)input; //converts to ASCII

  printf("The decimal representation is: %d\n", ascii);
  printf("The least significant bit is: %d",LEAST_BIT(ascii));
}
