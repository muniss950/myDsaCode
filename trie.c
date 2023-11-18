#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = false;
    for (int i = 0; i < 26; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(TrieNode* root, char* word) {
    TrieNode* node = root;
    int length = strlen(word);
    for (int i = 0; i < length; ++i) {
        int index = word[i] - 'a';
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}


bool search(TrieNode* root, char* word) {
    TrieNode* node = root;
    int length = strlen(word);
    for (int i = 0; i < length; ++i) {
        int index = word[i] - 'a';
        if (!node->children[index]) {
            return false; 
        }
        node = node->children[index];
    }
    return node != NULL && node->isEndOfWord;
}

void delete(TrieNode* root, char* word) {
    TrieNode* node = root;
    int length = strlen(word);
    for (int i = 0; i < length; ++i) {
        int index = word[i] - 'a';
        if (!node->children[index]) {
            return; 
        }
        node = node->children[index];
    }
    node->isEndOfWord = false;
}

void findLongestWord(TrieNode* root, char* currentWord, char* longest) {
    if (!root) {
        return;
    }
    if (root->isEndOfWord) {
        if (strlen(currentWord) > strlen(longest)) {
            strcpy(longest, currentWord);
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (root->children[i]) {
            char nextChar = 'a' + i;
            char nextWord[100];
            strcpy(nextWord, currentWord);
            strncat(nextWord, &nextChar, 1);
            findLongestWord(root->children[i], nextWord, longest);
        }
    }
}

void longestPrefixMatch(TrieNode* root, char* prefix, char* matchedPrefix) {
    TrieNode* node = root;
    int length = strlen(prefix);
    int matchedLength = 0;

    for (int i = 0; i < length; ++i) {
        int index = prefix[i] - 'a';
        if (!node->children[index]) {
            break;
        }
        node = node->children[index];
        matchedPrefix[matchedLength++] = prefix[i];
    }

    matchedPrefix[matchedLength] = '\0';
}

int main() {
    int q;
    scanf("%d", &q);

    TrieNode* root = createNode();
    char longestWord[100] = "";

    while (q--) {
        int a;
        char b[100];
        scanf("%d", &a);

        switch (a) {
            case 1:
                scanf("%s", b);
                insert(root, b);
                break;
            case 2:
                scanf("%s", b);
                delete(root, b);
                break;
            case 3:
                scanf("%s", b);
                printf("%s\n", search(root, b) ? "True" : "False");
                break;
            case 4:
                findLongestWord(root, "", longestWord);
                printf("%s\n", longestWord);
                break;
            case 5:
                scanf("%s", b);
                char matchedPrefix[100];
                longestPrefixMatch(root, b, matchedPrefix);
                printf("%s\n", matchedPrefix);
                break;
            default:
                break;
        }
    }

    return 0;
}
