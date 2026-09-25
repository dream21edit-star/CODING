#include <stdio.h>

int main() {
    int data[5] = {1, 3, 5, 7, 9};
    printf("Array element at index 2 (Value should be 5):\n");
    printf("1. Subscript notation: %d\n", data[2]);
    printf("2. Pointer notation (arr + 2): %d\n", *(data+2));
    int *ptr = data; // or &data[0]
    printf("3. Pointer notation (ptr + 2): %d\n", *(ptr+2));
    return 0;
}