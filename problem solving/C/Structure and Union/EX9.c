#include <stdio.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
int main() {
    Node n1, n2;
    n1.data = 100;
    n2.data = 200;
    n1.next = &n2;
    n2.next = NULL;
    printf("Node 1 Data: %d\nNode 2 Data (via n1 pointer): %d\n", n1.data, n1.next->data);
    return 0;
}