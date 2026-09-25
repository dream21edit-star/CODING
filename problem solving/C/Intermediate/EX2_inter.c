#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 6;
    int *T = (int*)malloc(n*sizeof(int));
    if(T == NULL) return 1;
    printf("Array allocated at Heap Address: %p\n", (void*)T);
    for(int i = 0; i<n; i++) {
        T[i] = (i+1)*100;
        printf("Value at index %d: %d\n", i, T[i]);
    }
    free(T);
    printf("Memory successfully freed.\n");
    return 0;
}