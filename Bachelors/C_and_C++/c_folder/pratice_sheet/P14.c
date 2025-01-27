#include <stdio.h>

struct Data {
    char letter;
    char text[3];
};

int main() {
    FILE *file = fopen("generate.txt", "wb");

    if (file == NULL) {
        perror("Error opening file");
        fclose(file);
        return 1;
    }

    struct Data data[10];

    // Initialize data with the specified format
    for (char letter = 'a'; letter <= 'j'; letter++) {
        data[letter - 'a'].letter = letter;
        sprintf(data[letter - 'a'].text, "%c%c", letter, letter);
    }

    // Write data to the file using fwrite
    fwrite(data, sizeof(struct Data), 10, file);

    // Close the file
    fclose(file);

    return 0;
}
