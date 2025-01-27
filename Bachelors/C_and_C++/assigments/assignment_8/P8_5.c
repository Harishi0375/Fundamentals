/*
CH-230-A
a8_5.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[3]; //array
    int sum;
    FILE *file1, *file2;

    file1 = fopen("chars.txt", "r"); // Open file1 for reading

    if (file1 == NULL) {
        printf("some error occured!\n");
        fclose(file1); //close file
        exit(1);
    }

    fgets(buff, 3, file1);
    
    sum = buff[0] + buff[1];

    fclose(file1); // Close file1

    file2 = fopen("codesum.txt", "w"); // Open file2 for writing

    if (file2 == NULL) {
        printf("some error occured!\n");
        fclose(file2); //close file
        exit(1);
    }

    fprintf(file2, "%d", sum); // Write the sum to file2
    fclose(file2); // Close file2

    return 0;
}
