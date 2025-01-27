/*
  CH-230-A
  a4_p11.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int count_insensitive(char *str, char c)
{
  int count = 0;
  const int len = strlen(str) - 1;
  for(int i = 0; i < len; ++i)
  {
    // convert both character input and char to be searched
    if(tolower(str[i]) != tolower(c))
    {
      continue;;
    }
    ++count;
  }

  return count;
}

int main()
{
  char str[50];
  fgets(str, sizeof(str), stdin); // Read a line of text using fgets
  const int length = strlen(str); // Calculate the length of the string

  // char c;
  char *newStr = (char*) malloc(length*sizeof(char));
  strcpy(newStr, str);

  char testOccurance[] = {'b', 'H', '8', 'u', '$'};

  for(int i = 0; i < 5; ++i)
  {
    int count = count_insensitive(newStr, testOccurance[i]);
    printf("The character %c occurs %d times \n", testOccurance[i], count);
  }

  free(newStr);

  return 0;
}