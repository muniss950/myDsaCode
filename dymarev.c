#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseWords(char *sentence);

int main() {
    char sentence[MAX_LENGTH];

    fgets(sentence, MAX_LENGTH, stdin);

    // Remove the newline character from the input
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    reverseWords(sentence);
    printf("%s",sentence);

    return 0;
}

void reverseWords(char *sentence) {
    char *start = sentence;
    char *end = sentence + strlen(sentence) - 1;

    // Reverse the entire sentence
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Reverse each word in the sentence
    start = end = sentence;
    while (*start) {
        while (*end && *end != ' ') {
            end++;
        }

        // Reverse the current word
        char *wordStart = start;
        char *wordEnd = end - 1;
        while (wordStart < wordEnd) {
            char temp = *wordStart;
            *wordStart = *wordEnd;
            *wordEnd = temp;
            wordStart++;
            wordEnd--;
        }

        // Move to the next word
        if (*end) {
            start = end + 1;
            end++;
        } else {
            break;
        }
    }
}
