/*
  CH-230-A
  a3_p2.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

int main() 
{
  char ch;
  int n;

  printf("enter the char phrase:"); //user to enter 2 letters
  scanf("%c",&ch);

  printf("Enter an integer:"); // the number of times to repeat n 
  scanf("%d", &n);

  printf("%c",ch);
  if (n > 0) //incase n is 0 
    {
      printf(", ");
    }
  for (int i = 1; i <= n; i++)
  {
    int assiiValue = (int)ch; // OR int asciiValue = ch
    assiiValue = assiiValue - i;
    printf("%c",(char)assiiValue);
    if (i < n)
    {
      printf(", ");
    }
    
  }
  return 0;
}
    
  
  

  




