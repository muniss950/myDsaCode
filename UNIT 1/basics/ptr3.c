#include <stdio.h>

int main() {
    int a;
    float b, c;
    double d;
    char ch;

    a = 10; b = 2.5; c = 12.36; d = 12345.66; ch = 'A';
    printf("%d is stored in location %p\n", a, &a);
    printf("%f is stored in location %p\n", b, &b);
    printf("%f is stored in location %p\n", c, &c);
    printf("%f is stored in location %p\n", d, &d);
    printf("%c is stored in location %p\n", ch, &ch);

    return 0;
}
