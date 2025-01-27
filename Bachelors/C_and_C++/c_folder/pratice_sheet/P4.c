#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int checkPassword(char ch[]);

int main()
{
    char ch[100];
    scanf("%s",ch);
    int returnType = checkPassword(ch);
    if (returnType == 1)
    {
        printf("1");
        return true;
    }
    printf("0");
    return false;
}


int checkPassword(char ch[])
{
    int length = strlen(ch);
    int numCount = 0;
    if (length < 8)
    {
        return - 1;
    }
    int count = 0;
    while (ch[count] != '\0')
    {
        for (int i = 0; i < length; i++)
        {
            if (isdigit(ch[i]))
            {
                numCount = numCount + 1;
            }
            count++;
        }
    }
    if (numCount < 3)
    {
        return -1;
    }
    return 1;  
}