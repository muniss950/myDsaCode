#include <stdio.h>

void modifyValue(int *ptr) {
    *ptr = 100; // This will modify the value of the variable outside the function.
}

int main() {
    int x = 10;
    printf("Original value of x: %d\n", x);

    modifyValue(&x); // Pass the address of x to the function.

    printf("Modified value of x: %d\n", x);

    return 0;
}





