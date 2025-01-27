#include <stdio.h>

void main()
{
  char a_string[] = "this is a string\0";
  char *p;
  int count = 0;
  printf("the string: %s\n", a_string); 
  p = a_string;
  while (*p != '\0')
  {
    p++;
    count++;
  } 
  printf("the string has %d characters. \n", count);
  printf("printing the reverse string: ");
  p--;
  while (count > 0)
  {
    printf("%c", *p); //the reverse order of the string
    p--;
    count--;
  }
  printf("\n"); 
}