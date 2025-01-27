/*
CH-230-A
a8_9.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    char fileNames[n][100]; //2d array

    for (int i = 0; i < n; i++)
    {
        scanf("%s", fileNames[i]);
    }
    
    FILE *outputFile = fopen("output.txt", "w+");

    for (int i = 0; i < n; i++)
    {
        printf("%d %s \n", i, fileNames[i]);
        FILE *file = fopen(fileNames[i], "r");       
        if (file == NULL) 
        {
            printf("error opening file %s !\n", fileNames[i]);
            fclose(file); //close file
            fclose(outputFile); //// Close the destination file before exiting
            exit(1);
        }

        char ch = fgetc(file);
        if (ch != EOF)
        {
            fprintf(outputFile, "%c", ch); 
        }

        while ((ch = fgetc(file)) != EOF) {
            fputc(ch, outputFile); //copy content 
        }
        
        fprintf(outputFile, "\n");
        fclose(file);
    }

    fclose(outputFile);
}