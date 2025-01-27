#include <stdio.h>


int add(int numbers[], int numValues)
{
    int *ptr = numbers;
    int sum = 0;
    for(int i = 0; i < numValues; ++i)
    {
        sum += *(ptr + i);
    }


    // int **dPtr = NULL;

    


    // for(int i = 0; i < numValues; ++i)
    // {
    //     sum += numbers[i];
    // }

    return sum;
}

void algebra();

int main()
{
    printf("Hello World from c \n\n");

    int numbers[5] = {3, 2, 1, 5, 6}; 
    int sum = add(numbers, 5);

    printf("sum of numbers %d \n", sum);
    algebra();
    return 0;
}



