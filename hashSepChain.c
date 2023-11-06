#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[HASH_SIZE];
} HashTable;

void initHashTable(HashTable* ht);
int customHash(int key) ;
bool search(HashTable* ht, int key);
void insert(HashTable* ht, int key); 
void delete(HashTable* ht, int key); 

int main() {
    HashTable ht;

    initHashTable(&ht);

    int q;

    scanf("%d", &q);

    while (q--) {
        int operation, key;

        scanf("%d %d", &operation, &key);

        if (operation == 1) {

            insert(&ht, key);
        } else if (operation == 2) {

            bool found = search(&ht, key);

            printf(found ? "true\n" : "false\n");
        } else if (operation == 3) {

            delete(&ht, key);
        }
    }

    return 0;
}
void initHashTable(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

int customHash(int key) {
    return key % HASH_SIZE;
}

void insert(HashTable* ht, int key) {
    int index = customHash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

bool search(HashTable* ht, int key) {
    int index = customHash(key);
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void delete(HashTable* ht, int key) {
    int index = customHash(key);
    Node* current = ht->table[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
