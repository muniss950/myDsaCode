#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[1]; // Pointer to the second element of the array
    int *ptr2 = &arr[4]; // Pointer to the last element of the array

    printf("Initial pointers:\n");
    printf("Pointer 1 address: %p, value: %d\n", ptr1, *ptr1);
    printf("Pointer 2 address: %p, value: %d\n", ptr2, *ptr2);

    // Subtracting one pointer from another
    char *diff = (ptr2 * ptr1);

    printf("\nPointer difference: %p\n", diff);

    return 0;
}
