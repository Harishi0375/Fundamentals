#include <stdio.h>

int main()
{
 float result;
 float a = 5.0; //result stored as float so data type of a is float
 float b = 13.5; //result stored as float so data type of b is float
 result = a/b;
 printf("the result is %f\n",result); //float hence %d to %f and /n become \n syntax error for next line
 return 0;   
}