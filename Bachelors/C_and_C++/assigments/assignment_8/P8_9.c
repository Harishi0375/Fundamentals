/*
CH-230-A
a8_9.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    char ch;
    scanf("%d", &n);

    FILE *files[n], *destination;

    destination = fopen("output.txt", "w+");
    if (destination == NULL) {
        printf("Error: Could not open the output file!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        char filename[100];
        scanf("%s", filename);
        files[i] = fopen(filename, "r");
        if (files[i] == NULL) {
            printf("Error: Could not open the file '%s'!\n", filename);
            fclose(destination); // Close the destination file before exiting
            return 1;
        }

        while ((ch = fgetc(files[i])) != EOF) {
            fputc(ch, destination);
        }
        fprintf(destination, "\n");
        fclose(files[i]); // Close the individual file after copying its content
    }

    fclose(destination); // Close the destination file after copying all contents
    return 0;
}
