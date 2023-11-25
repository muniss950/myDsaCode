#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to initialize an adjacency matrix
void initializeMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            matrix[i][j] = 0;  // Initialize all elements to 0
        }
    }
}

// Function to add an edge to the adjacency matrix
void addEdge(int matrix[MAX_VERTICES][MAX_VERTICES], int startVertex, int endVertex) {
    matrix[startVertex][endVertex] = 1;
    matrix[endVertex][startVertex] = 1;  // Assuming an undirected graph
}

// Function to print the adjacency matrix
void printMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    initializeMatrix(adjacencyMatrix, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Input edges
    for (int i = 0; i < numEdges; ++i) {
        int startVertex, endVertex;
        printf("Enter edge (startVertex endVertex): ");
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(adjacencyMatrix, startVertex, endVertex);
    }

    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    printMatrix(adjacencyMatrix, numVertices);

    return 0;
}
