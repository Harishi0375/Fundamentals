/*
CH-230-A
a8_8.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    FILE *file1;
    char filename[100];
    char arr[500];
    int count = 0;
    int total = 0;
    char c;

    scanf("%s", filename);
    file1 = fopen(filename, "r"); // Open file1 for reading

    if (file1 == NULL) {
        printf("Error: Could not open the file!\n");
        exit(1);
    }

    while ((c = fgetc(file1)) != EOF) 
    {
        arr[count] = c;
        ++count;
    }
    arr[count] = '\0'; // Null-terminate the string

    fclose(file1); // Close the file

    for (int i = 0; i < count; i++) // Count words
    {
        if (isalpha(arr[i])) {
            while (isalpha(arr[i])) // Skip characters until a non-alphabetic character is encountered
            {
                ++i;
            }
            ++total;
        }
    }

    printf("The file contains %d words\n", total);

    return 0;
}
