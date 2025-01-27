/*
  CH-230-A
  a3_p3.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

float convert(int cm)
{
    return (float)cm / 100000.0; // formula to convert cm to km
}

int main()
{
    int LengtInCm;
    scanf("%d",&LengtInCm);
    
    float LengthInKm = convert(LengtInCm); //using the function for conversion 
    printf("Result of conversion: %lf\n",LengthInKm);

    return 0; 
    
}