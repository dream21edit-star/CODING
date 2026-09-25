#include <stdio.h>
void increment_value(int *ptr) {
    (*ptr)++;
}
int main() {
    
    int count = 10;
    printf("Before function call, count = %d\n", count);
    increment_value(&count);
    printf("After function call, count = %d\n", count);
    return 0;
}
