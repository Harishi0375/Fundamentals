#include <stdio.h>

int main()
{
    int max = 0;
    int array[5] = {3,6,10,5,7};
    for (int i = 0; i <= 5 ; i++)
    {
      if (array[i] > max)
      {
        max = array[i];
      }
        
    }
    printf("the max value is: %d",max);
    return 0; 
}