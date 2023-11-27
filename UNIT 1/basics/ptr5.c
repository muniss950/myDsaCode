#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element of the array

    printf("Initial pointer address: %d\n", ptr);

    // Adding an integer to the pointer
    ptr = ptr + 10; // Incrementing the pointer by 2 integer positions

    printf("After adding 2 integer positions: %d\n", ptr);
    printf("Value at the new pointer position: %d\n", *ptr);

    return 0;
}
