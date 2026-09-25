#include <stdio.h>
int main() {
    int a=10;
    float b = 20.5f;
    int *p_a;
    p_a = &a;
    printf("Address of integer variable 'a': %p\n", &a);
    printf("Address of float variable 'b': %p\n", &b);
    printf("Address stored IN pointer 'p_a': %p\n", p_a);
    printf("Address of pointer variable 'p_a' itself: %p\n", &p_a);
    return 0;
}