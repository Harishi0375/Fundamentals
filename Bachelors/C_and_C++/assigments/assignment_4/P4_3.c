/*
  CH-230-A
  a4_p3.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <math.h>

float geometric_mean(float arr[], int num);


int main()
{
  float arr[15];
  char letter;
  int num;
  float value; //case 'm'
  float low = 0.0; //case 'l'
  float max = 0.0; //case 'h'
  float sum = 0.0; //case 's'
  for (int i = 0; i <= 14; i++)
  {
    printf("enter a float: ");
    scanf("%f", &arr[i]);
    if (arr[i] < 0.0)
    {
      num = i - 1; //because i starts from 0
      break;
    }  
  }
  printf("\n");
  printf("enter a letter:"); //m,h,l,s
  scanf(" %c", &letter);
  switch (letter)
  {
  case 'm':  
    value = geometric_mean(arr,num);
    printf("the geometric mean is: %f\n",value); //mean
    break;
  case 'h':
    for (int i = 0; i <= num; i++)
    {
      if (arr[i] > max)
      {
        max = arr[i];
      }  
    }
    printf("the highest number in the array is: %f\n",max); //max
    break;
  case 'l':
    low = arr[0];
    for (int i = 0; i <= num; i++)
    {
      if (arr[i] < low)
      {
        low = arr[i];
      }  
    }
    printf("the smallest number in the array is: %f\n",low); //low
    break;
  case 's':
    for (int i = 0; i <= num; i++)
    {
      sum = sum + arr[i];
    }
    printf("the sum of all the elements in the array is: %f\n",sum); //sum
    break;
  
  default:
    printf("wrong input"); // just for validation
    break;
  }
  return 0;  
}

float geometric_mean(float arr[],int num)
{
  float geomean;
  float length = num + 1; 
  float product = 1.0; //initialisation 
  for (int i = 0; i <= num; i++)
  {
    product = product * arr[i];
  }
  geomean = pow(product, 1.0/length); //power function
  return geomean;
}

