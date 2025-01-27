/*
CH-230-A
a8_7.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1,ch2; 
    FILE *file1, *file2, *file3;
    file1 = fopen("text1.txt","r"); //file 1
    file2 = fopen("text2.txt","r"); //file 2

    if (file1 == NULL || file2 == NULL ) 
    {
        printf("error opening file(s)!");
        fclose(file1); //close file 1
        fclose(file2); //close file 2
        exit(1); //exit
    }

    file3 = fopen("merge12.txt","w+");

    while ((ch1 = fgetc(file1)) != EOF) 
    {
        fputc(ch1, file3);
    }

    fprintf(file3, "\n");

    while ((ch2 = fgetc(file2)) != EOF) 
    {
        fputc(ch2, file3);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    exit(1);

    return 1;
}