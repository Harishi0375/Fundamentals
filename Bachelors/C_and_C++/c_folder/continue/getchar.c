#include <stdio.h>

int main()
{
    char c; //code assumes that the input is provided in one line like: "abf23" 
    while ((c = getchar()) != '\n')
    {
        if (c == 'b')
        {
            continue;
        }
        printf("%c",c);
    }
    return 0;
}