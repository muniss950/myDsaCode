#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = &arr[4]; // Pointer to the last element of the array

    printf("Initial pointer address: %d\n", ptr);

    // Subtracting an integer from the pointer
    ptr = ptr - 2; // Decrementing the pointer by 2 integer positions

    printf("After subtracting 2 integer positions: %d\n", ptr);
    printf("Value at the new pointer position: %d\n", *ptr);

    return 0;
}
