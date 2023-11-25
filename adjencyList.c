#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the adjacency list
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the adjacency list
void printAdjList(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Adjacency list for vertex %d: ", i);
        struct Node* temp = graph->adjList[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* current = graph->adjList[i];
        while (current) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    // Number of vertices in the graph
    int numVertices = 5;

    // Create a graph with 'numVertices' vertices
    struct Graph* graph = createGraph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list
    printAdjList(graph);

    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}
