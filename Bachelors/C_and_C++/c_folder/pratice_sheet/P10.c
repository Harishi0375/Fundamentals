#include <stdio.h>
#include <stdlib.h>

// Function to print the matrix
void print_matrix(int **A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    FILE *fptr;

    // Open the file for reading
    fptr = fopen("matrix.dat", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of rows and columns
    fscanf(fptr, "%d", &rows);
    fscanf(fptr, "%d", &cols);

    // Allocate memory for the matrix
    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int *));
    }

    // Read matrix values from the file
    int row, col, value;
    while (fscanf(fptr, "%d %d %d", &row, &col, &value) == 3) {
        matrix[row-1][col-1] = value;
    }

    // Close the file
    fclose(fptr);

    // Print the matrix using the print_matrix function
    print_matrix(matrix, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

