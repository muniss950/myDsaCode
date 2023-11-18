
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

typedef struct {
    LinkedList* array;
    int size;
} SudokuGraph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

// Function to add an edge to the graph
void addEdge(SudokuGraph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to clear the adjacency list for a cell
void clearAdjacencyList(SudokuGraph* graph, int cell) {
    Node* current = graph->array[cell].head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    graph->array[cell].head = NULL;
}

// Function to update the adjacency list after placing a number in a cell
void updateAdjacencyList(SudokuGraph* graph, int row, int col, int num) {
    int cell = row * 9 + col;

    // Clear the adjacency list for the current cell
    clearAdjacencyList(graph, cell);

    // Update the adjacency list based on the new number in the cell
    for (int i = 0; i < graph->size; i++) {
        int neighborCell = row * 9 + i;  // Update row
        if (i != col) {
            addEdge(graph, cell, neighborCell);
        }

        neighborCell = i * 9 + col;  // Update column
        if (i != row) {
            addEdge(graph, cell, neighborCell);
        }

        // Update 3x3 subgrid
        int subgridStartI = 3 * (row / 3);
        int subgridStartJ = 3 * (col / 3);
        for (int x = subgridStartI; x < subgridStartI + 3; x++) {
            for (int y = subgridStartJ; y < subgridStartJ + 3; y++) {
                neighborCell = x * 9 + y;
                if (neighborCell != cell) {
                    addEdge(graph, cell, neighborCell);
                }
            }
        }
    }
}

// Function to generate the adjacency list for a Sudoku puzzle
void generateAdjacencyList(SudokuGraph* graph) {
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {
            int cell = i * graph->size + j;
            for (int k = 0; k < graph->size; k++) {
                if (k != j) {
                    addEdge(graph, cell, i * graph->size + k);  // Connect to cells in the same row
                }
                if (k != i) {
                    addEdge(graph, cell, k * graph->size + j);  // Connect to cells in the same column
                }

                // Connect to cells in the same 3x3 subgrid
                int subgridStartI = 3 * (i / 3);
                int subgridStartJ = 3 * (j / 3);
                for (int x = subgridStartI; x < subgridStartI + 3; x++) {
                    for (int y = subgridStartJ; y < subgridStartJ + 3; y++) {
                        int neighbor = x * graph->size + y;
                        if (neighbor != cell) {
                            addEdge(graph, cell, neighbor);
                        }
                    }
                }
            }
        }
    }
}

// Function to free memory allocated for the graph
void freeGraph(SudokuGraph* graph) {
    for (int i = 0; i < graph->size * graph->size; i++) {
        Node* current = graph->array[i].head;
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);
}

// Function to print the Sudoku puzzle
void printSudoku(int puzzle[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a cell
bool isSafe(int puzzle[9][9], int row, int col, int num) {
    // Check if the number is not present in the current row and column
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == num || puzzle[i][col] == num) {
            return false;
        }
    }

    // Check if the number is not present in the current 3x3 subgrid
    int subgridStartRow = 3 * (row / 3);
    int subgridStartCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[subgridStartRow + i][subgridStartCol + j] == num) {
                return false;
            }
        }
    }

    return true;  // If the number satisfies all constraints
}

// Function to find an empty cell in the puzzle
bool findEmptyCell(int puzzle[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (puzzle[*row][*col] == 0) {
                return true;  // Found an empty cell
            }
        }
    }
    return false;  // No empty cell found
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int puzzle[9][9], SudokuGraph* graph) {
    int row, col;

    // If there is no empty cell, the puzzle is solved
    if (!findEmptyCell(puzzle, &row, &col)) {
        return true;
    }

    // Try filling the empty cell with a number
    for (int num = 1; num <= 9; num++) {
        // Check if the number satisfies Sudoku constraints
        if (isSafe(puzzle, row, col, num)) {
            // Place the number in the cell
            puzzle[row][col] = num;

            // Update the adjacency list
            updateAdjacencyList(graph, row, col, num);

            // Recursively try to solve the rest of the puzzle
            if (solveSudoku(puzzle, graph)) {
                return true;  // Puzzle solved successfully
            }

            // If placing the number doesn't lead to a solution, backtrack
            puzzle[row][col] = 0;

            // Clear the adjacency list for the backtracked cell
            clearAdjacencyList(graph, row * 9 + col);
        }
    }

    return false;  // No solution found
}

// Function to take user input for Sudoku puzzle and solve it
void userInputSudoku(int puzzle[9][9], SudokuGraph* graph) {
    int row, col, num;

    // Find the first empty cell
    if (!findEmptyCell(puzzle, &row, &col)) {
        printf("The Sudoku puzzle is already solved.\n");
        printSudoku(puzzle);
        return;
    }

    while (true) {
        // Print the current state of the Sudoku puzzle
        printf("\nCurrent Sudoku puzzle:\n");
        printSudoku(puzzle);

        // Ask the user to input values for a cell
        printf("\nEnter the row (1-9), column (1-9), and number (1-9) separated by spaces (enter -1 to exit): ");
        scanf("%d %d %d", &row, &col, &num);

        // Check if the user wants to exit
        if (row == -1 || col == -1 || num == -1) {
            break;
        }

        // Check if the entered values are within the valid range
        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("Invalid input. Please enter values within the range 1-9.\n");
            continue;
        }

        // Convert row and column values to 0-based indexing
        row--;
        col--;

        // Check if the entered cell is not empty
        if (puzzle[row][col] != 0) {
            printf("Cell (%d, %d) is already filled. Choose an empty cell.\n", row + 1, col + 1);
            continue;
        }

        // Check if the entered number satisfies Sudoku constraints
        if (!isSafe(puzzle, row, col, num)) {
            printf("Invalid move. Please choose a different number.\n");
            continue;
        }

        // Update the puzzle and adjacency list
        puzzle[row][col] = num;
        updateAdjacencyList(graph, row, col, num);

        // Print the intermediate state of the Sudoku puzzle
        printf("\nIntermediate Sudoku puzzle:\n");
        printSudoku(puzzle);

        // Check if the puzzle is solved after each move
        if (!findEmptyCell(puzzle, &row, &col)) {
            printf("\nCongratulations! You solved the Sudoku puzzle.\n");
            printSudoku(puzzle);
            break;
        }
    }
}

int main() {
    // Create a SudokuGraph instance
    SudokuGraph* sudokuGraph = (SudokuGraph*)malloc(sizeof(SudokuGraph));
    sudokuGraph->size = 9;
    sudokuGraph->array = (LinkedList*)malloc(sudokuGraph->size * sudokuGraph->size * sizeof(LinkedList));

    // Initialize linked lists in the array
    for (int i = 0; i < sudokuGraph->size * sudokuGraph->size; i++) {
        sudokuGraph->array[i] = *createLinkedList();
    }

    // Generate adjacency list for a 9x9 Sudoku puzzle
    generateAdjacencyList(sudokuGraph);

    // Input the Sudoku puzzle
    int puzzle[9][9];
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }

    // Print the initial Sudoku puzzle
    printf("Initial Sudoku puzzle:\n");
    printSudoku(puzzle);

    // User input for Sudoku
    userInputSudoku(puzzle, sudokuGraph);

    // Free memory
    freeGraph(sudokuGraph);

    return 0;
}
