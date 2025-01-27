#include <stdio.h>

int main()
{
    char c = 'F';
    printf("the character is: %c\n",c);
    printf("ASCII value is: %d\n",(char)70);
    int pointer = 71;
    while(pointer <= 73)
    {
        printf("the character is: %c\n ASCII value is: %d\n",pointer, pointer);
        pointer = pointer + 1;    
    }
}