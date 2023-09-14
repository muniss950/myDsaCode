#include <stdio.h>
#include <stdlib.h>

struct MatrixElement {
    int row;
    int col;
    int value;
    struct MatrixElement* right; // Pointer to the next element in the same row
    struct MatrixElement* down;  // Pointer to the next element in the same column
};

struct SparseMatrix {
    int rows;
    int cols;
    struct MatrixElement** row_heads; // Array of row heads
    struct MatrixElement** col_heads; // Array of column heads
};

struct MatrixElement* createMatrixElement(int row, int col, int value) {
    struct MatrixElement* newElement = (struct MatrixElement*)malloc(sizeof(struct MatrixElement));
    if (newElement == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newElement->row = row;
    newElement->col = col;
    newElement->value = value;
    newElement->right = NULL;
    newElement->down = NULL;
    return newElement;
}

struct SparseMatrix* createSparseMatrix(int rows, int cols) {
    struct SparseMatrix* matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    matrix->rows = rows;
    matrix->cols = cols;

    // Allocate memory for row and column heads
    matrix->row_heads = (struct MatrixElement**)malloc(rows * sizeof(struct MatrixElement*));
    matrix->col_heads = (struct MatrixElement**)malloc(cols * sizeof(struct MatrixElement*));

    if (matrix->row_heads == NULL || matrix->col_heads == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize row and column heads
    for (int i = 0; i < rows; i++) {
        matrix->row_heads[i] = NULL;
    }
    for (int j = 0; j < cols; j++) {
        matrix->col_heads[j] = NULL;
    }

    return matrix;
}

void insertElement(struct SparseMatrix* matrix, int row, int col, int value) {
    struct MatrixElement* newElement = createMatrixElement(row, col, value);

    // Insert into the row
    newElement->right = matrix->row_heads[row];
    matrix->row_heads[row] = newElement;

    // Insert into the column
    newElement->down = matrix->col_heads[col];
    matrix->col_heads[col] = newElement;
}

void displaySparseMatrix(struct SparseMatrix* matrix) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < matrix->rows; i++) {
        struct MatrixElement* current = matrix->row_heads[i];
        for (int j = 0; j < matrix->cols; j++) {
            if (current != NULL && current->col == j) {
                printf("%d ", current->value);
                current = current->right;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void freeSparseMatrix(struct SparseMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        struct MatrixElement* current = matrix->row_heads[i];
        while (current != NULL) {
            struct MatrixElement* temp = current;
            current = current->right;
            free(temp);
        }
    }

    free(matrix->row_heads);

    for (int j = 0; j < matrix->cols; j++) {
        struct MatrixElement* current = matrix->col_heads[j];
        while (current != NULL) {
            struct MatrixElement* temp = current;
            current = current->down;
            free(temp);
        }
    }

    free(matrix->col_heads);
    free(matrix);
}

int main() {
    struct SparseMatrix* matrix = createSparseMatrix(3, 3);

    // Insert elements into the sparse matrix
    insertElement(matrix, 0, 0, 1);
    insertElement(matrix, 1, 1, 2);
    insertElement(matrix, 2, 2, 3);
    insertElement(matrix, 1, 2, 4);

    // Display the sparse matrix
    displaySparseMatrix(matrix);

    // Free memory
    // freeSparseMatrix(matrix);

    return 0;
}

