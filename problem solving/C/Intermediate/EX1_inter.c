#include <stdio.h>

void swap(int *a, int *b) {
    printf("Before Swap: x = %d, y= %d\n", *a, *b);
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("After Swap: x= %d, y = %d\n", *a, *b);
}
int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    return 0;
}
