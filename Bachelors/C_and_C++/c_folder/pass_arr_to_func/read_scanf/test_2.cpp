#include <stdio.h>
// this code prints the address location stored by the value 
int main()
{
    char value[100] = "";
    printf("enter a value");
    scanf("%d", &value);
    printf("you entered: %d\n",value);
    return 0;
}