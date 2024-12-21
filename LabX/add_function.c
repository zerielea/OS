#include <stdio.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int x = 3, y = 5, z = 7, sum;

    add(&x, &y, &z, &sum);

    printf("Sum: %d\n", sum);
    return 0;
}
