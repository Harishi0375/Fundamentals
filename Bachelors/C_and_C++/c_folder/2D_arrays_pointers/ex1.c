#include <stdio.h>
#include <stdlib.h>

void set_all_elements(int** arr, int numrow, int numcol) {
    // Loop through each row and column and set array elements
    for (int r = 0; r < numrow; r++)
        for (int c = 0; c < numcol; c++)
            arr[r][c] = r * c; // Initialize elements with the product of row and column indices
}

int main() {
    int** table;
    int numrows = 3;
    int numcols = 4;

    // Allocate memory for array of pointers (rows)
    table = (int**)malloc(sizeof(int*) * numrows);
    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        exit(1);
    }

    // Allocate memory for each row (array of integers)
    for (int row = 0; row < numrows; row++) {
        table[row] = (int*)malloc(sizeof(int) * numcols);
        if (table[row] == NULL) {
            fprintf(stderr, "Memory allocation failed for columns in row %d.\n", row);
            exit(1);
        }
    }

    // Call function to set elements of the array
    set_all_elements(table, numrows, numcols);

    // Print the initialized 2D array
    printf("Initialized 2D Array:\n");
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < numcols; c++) {
            printf("%3d ", table[r][c]); // Print array elements
        }
        printf("\n");
    }

    // Free allocated memory
    for (int row = 0; row < numrows; row++) {
        free(table[row]); // Free memory for each row
    }
    free(table); // Free memory for array of pointers

    return 0;
}
