/*
  CH-230-A
  a4_p12.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>

void replaceALL(char *str, char c, char e);
int string_length; //global
int main()
{
  char str[80];
  char c,e;
  while (1)
  {
    printf("write sentence: \n");
    fgets(str, sizeof(str), stdin); //using fgets as fscan is not accurate

    // exit loop on stop input
    if (strcmp(str, "stop") == 1)  //compare function 
    {
      break;
    }
    
    string_length = strlen(str) - 1; //takes the string length to use it in replaceAll
    printf("type the character you want to replace: ");
    scanf(" %c", &c);
    printf("type the new character: ");
    scanf(" %c",&e); 
    replaceALL(str,c,e);
    printf("changed string is: \n");
    printf("%s", str);
    fflush(stdin);    
  }
  return 0;
}


void replaceALL(char *str, char c, char e)
{
  for (int i = 0; i < string_length; ++i)
  {
      if (str[i] != c)
      {
        continue; //if its the value then it ignores
      }
      str[i] = e;
  }
}