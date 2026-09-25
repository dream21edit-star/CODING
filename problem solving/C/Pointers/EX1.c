#include <stdio.h>
#include <stdlib.h>
int main() {
    int var = 42;
    int *ptr;
    ptr = &var;

    printf("Variable 'var' value: %d\n", var);
    printf("Variable 'var' adress: %p\n", &var);
    printf("Pointer 'ptr' address (value of ptr): %p\n", ptr);
    printf("Value accessed via pointer (*ptr): %d\n", *ptr);
    return 0;
}