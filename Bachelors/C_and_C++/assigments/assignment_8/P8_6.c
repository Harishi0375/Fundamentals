/*
CH-230-A
a8_6.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>


int main() 
{
    FILE *file1, *file2, *file3;
    char fileName1[100], fileName2[100];
    printf("enter the 2 files names: \n");

    scanf("%s", fileName1);
    scanf("%s", fileName2);

    file1 = fopen(fileName1, "r"); // Open file1 for reading

    if (file1 == NULL) 
    {
        printf("error opening file %s !\n", fileName1);
        fclose(file1); //close file
        exit(1);
    }

    file2 = fopen(fileName2, "r"); // Open file1 for reading
    
    if (file2 == NULL) 
    {
        printf("error opening file %s !\n", fileName2);
        fclose(file2); //close file
        exit(1);
    }

    double no1, no2;
    fscanf(file1, "%lf", &no1); //read content of a file1 as double
    fscanf(file2, "%lf", &no2); //read content of a file2 as double
    fclose(file1); //close file
    fclose(file2); //close file

    double sum = no1 + no2; //sum
    double difference = no1 - no2; //difference
    double product = no1 * no2; //product
    double division = no1 / no2; //division

    file3 = fopen("results.txt", "w+"); //read and write operation
    fprintf(file3, "%lf\n", sum);
    fprintf(file3, "%lf\n", difference);
    fprintf(file3, "%lf\n", product);
    fprintf(file3, "%lf", division);
    fclose(file3);
}


