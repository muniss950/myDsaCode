#include <stdio.h>
#include <stdlib.h>

// Define a structure for a matrix element
struct MatrixElement {
    int row;
    int col;
    int value;
    struct MatrixElement* nextRow;
    struct MatrixElement* nextCol;
};

// Function to create a new matrix element
struct MatrixElement* createMatrixElement(int row, int col, int value) {
    struct MatrixElement* newElement = (struct MatrixElement*)malloc(sizeof(struct MatrixElement));
    if (newElement == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newElement->row = row;
    newElement->col = col;
    newElement->value = value;
    newElement->nextRow = NULL;
    newElement->nextCol = NULL;
    return newElement;
}

// Function to insert an element into the matrix
void insertElement(struct MatrixElement* *header, int row, int col, int value) {
    struct MatrixElement* newElement = createMatrixElement(row, col, value);
    if (*header == NULL) {
        *header = newElement;
        (*header)->nextRow = *header;
        (*header)->nextCol = *header;
    } else {
        struct MatrixElement* tempRow = (*header)->nextRow;
        struct MatrixElement* tempCol = (*header)->nextCol;

        while (tempRow != *header && tempRow->row < row) {
            tempRow = tempRow->nextRow;
        }

        while (tempCol != *header && tempCol->col < col) {
            tempCol = tempCol->nextCol;
        }

        newElement->nextRow = tempRow->nextRow;
        tempRow->nextRow = newElement;

        newElement->nextCol = tempCol->nextCol;
        tempCol->nextCol = newElement;
    }
}

// Function to display the sparse matrix
void displayMatrix(struct MatrixElement* header, int numRows, int numCols) {
    struct MatrixElement* currentRow = header->nextRow;
    
    for (int i = 0; i < numRows; i++) {
        struct MatrixElement* currentCol = currentRow;
        for (int j = 0; j < numCols; j++) {
            if (currentCol != header && currentCol->col == j) {
                printf("%d ", currentCol->value);
                currentCol = currentCol->nextCol;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
        currentRow = currentRow->nextRow;
    }
}

int main() {
    int numRows, numCols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &numRows, &numCols);

    struct MatrixElement* header = NULL;

    int row, col, value;
    printf("Enter the elements (row, column, value) for the sparse matrix (Enter -1 to stop):\n");
    while (1) {
        scanf("%d", &row);
        if (row == -1) break;
        scanf("%d %d", &col, &value);
        insertElement(&header, row, col, value);
    }

    printf("Sparse Matrix:\n");
    displayMatrix(header, numRows, numCols);

    return 0;
}

