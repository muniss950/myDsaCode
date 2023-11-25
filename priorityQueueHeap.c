#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to initialize an empty priority queue
void initializePriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to swap two elements in the priority queue
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property by moving the element up
void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && pq->elements[index].priority < pq->elements[parent].priority) {
        swap(&pq->elements[index], &pq->elements[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to maintain the min-heap property by moving the element down
void heapifyDown(PriorityQueue *pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < pq->size && pq->elements[leftChild].priority < pq->elements[smallest].priority) {
        smallest = leftChild;
    }

    if (rightChild < pq->size && pq->elements[rightChild].priority < pq->elements[smallest].priority) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&pq->elements[index], &pq->elements[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to insert an element into the priority queue
void enqueue(PriorityQueue *pq, int data, int priority) {
    if (pq->size >= MAX_SIZE) {
        printf("Queue overflow\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    pq->elements[pq->size] = newElement;
    pq->size++;

    heapifyUp(pq, pq->size - 1);
}

// Function to remove and return the element with the highest priority
Element dequeue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue underflow\n");
        Element emptyElement = {0, 0};
        return emptyElement;
    }

    Element front = pq->elements[0];
    pq->size--;

    if (pq->size > 0) {
        pq->elements[0] = pq->elements[pq->size];
        heapifyDown(pq, 0);
    }

    return front;
}

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    // Enqueue some elements with priorities
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);

    // Dequeue and print elements with highest priority
    Element e1 = dequeue(&pq);
    printf("Dequeued: Data=%d, Priority=%d\n", e1.data, e1.priority);

    Element e2 = dequeue(&pq);
    printf("Dequeued: Data=%d, Priority=%d\n", e2.data, e2.priority);

    Element e3 = dequeue(&pq);
    printf("Dequeued: Data=%d, Priority=%d\n", e3.data, e3.priority);

    return 0;
}
