#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *textFile, *binaryFile;

    // Open the text file for reading
    textFile = fopen("input.txt", "r");
    if (textFile == NULL) {
        perror("Error opening text file");
        return 1;
    }

    // Open the binary file for writing
    binaryFile = fopen("output.bin", "wb");
    if (binaryFile == NULL) {
        perror("Error opening binary file");
        fclose(textFile);
        return 1;
    }

    // Copy data from text file to binary file
    // int ch;
    // while ((ch = fgetc(textFile)) != EOF) {
    //     fputc(ch, binaryFile);
    // }
    while (!feof(textFile))
    {
        int ch = getc(textFile);
        if (ch != EOF)
        {
            fputc(ch,binaryFile);
        }
    }
    

    // Close the files
    fclose(textFile);
    fclose(binaryFile);

    printf("Text file data copied to binary file successfully.\n");

    return 0;
}
