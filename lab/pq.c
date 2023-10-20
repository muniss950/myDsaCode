#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue {
    int* elements;
    int capacity;
    int size;
};

void swap(int* a, int* b); 
struct PriorityQueue* createPriorityQueue(int capacity); 
void heapify(struct PriorityQueue* pq, int i);
void enqueue(struct PriorityQueue* pq, int value); 
int dequeue(struct PriorityQueue* pq); 
int peek(struct PriorityQueue* pq); 

int main() {
    int capacity;
    scanf("%d", &capacity);
    struct PriorityQueue* pq = createPriorityQueue(capacity);
    while (1) {
        int command;
        scanf("%d", &command);
        if (command == 0) {
            break;
        }
        if (command == 1) {
            int value;
            scanf("%d", &value);
            enqueue(pq, value);
        } else if (command == 2) {
            int value = dequeue(pq);
            if (value != -1) {
                printf("%d\n", value);
            }
        } else if (command == 3) {
            int value = peek(pq);
            if (value != -1) {
                printf("%d\n", value);
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    free(pq->elements);
    free(pq);
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->elements = (int*)malloc(capacity * sizeof(int));
    return pq;
}

void heapify(struct PriorityQueue* pq, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < pq->size && pq->elements[l] < pq->elements[smallest]) {
        smallest = l;
    }

    if (r < pq->size && pq->elements[r] < pq->elements[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&pq->elements[i], &pq->elements[smallest]);
        heapify(pq, smallest);
    }
}

void enqueue(struct PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->elements = (int*)realloc(pq->elements, pq->capacity * sizeof(int));
    }
    pq->elements[pq->size] = value;
    int i = pq->size;
    pq->size++;

    while (i > 0 && pq->elements[(i - 1) / 2] >= pq->elements[i]) {
        swap(&pq->elements[(i - 1) / 2], &pq->elements[i]);
        i = (i - 1) / 2;
    }
}

int dequeue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1;
    }
    int value = pq->elements[0];
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;
    for (int i = pq->size / 2; i >= 0; i--) {
        heapify(pq, i);
    }
    return value;
}

int peek(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1;
    }
    return pq->elements[0];
}

