#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10 
typedef struct HashTable {
    int table[TABLE_SIZE];

    bool occupied[TABLE_SIZE];
} HashTable;

int customHash(int key) {

    return key % TABLE_SIZE;
}
void initHashTable(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {

        hashTable->occupied[i] = false;
    }
}
void insert(HashTable *hashTable, int key) {
    int index = customHash(key);

    while (hashTable->occupied[index]) {

        index = (index + 1) % TABLE_SIZE; 
    }
    hashTable->table[index] = key;

    hashTable->occupied[index] = true;
}
bool search(HashTable *hashTable, int key) {
    int index = customHash(key);

    int originalIndex = index; 
    while (hashTable->occupied[index]) {

        if (hashTable->table[index] == key) {
            return true; 
        }
        index = (index + 1) % TABLE_SIZE; 

        if (index == originalIndex) {
            break;
        }
    }
    return false;
}
void delete(HashTable *hashTable, int key) {
    int index = customHash(key);

    int originalIndex = index; 
    while (hashTable->occupied[index]) {

        if (hashTable->table[index] == key) {

            hashTable->occupied[index] = false; 
            return;
        }
        index = (index + 1) % TABLE_SIZE; 

        if (index == originalIndex) {

            break; 
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);
    HashTable hashTable;
    initHashTable(&hashTable);

    while (q--) {
        int operation, key;
        scanf("%d %d", &operation, &key);
        if (operation == 1) {
            insert(&hashTable, key);
        } else if (operation == 2) {
            bool found = search(&hashTable, key);
            printf(found ? "true\n" : "false\n");
        } else if (operation == 3) {
            delete(&hashTable, key);
        }
    }

    return 0;
}
