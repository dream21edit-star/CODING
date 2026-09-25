#include <stdio.h>
int main() {
    int a, b;
    printf("Enter the first integer: "); scanf("%d", &a);
    printf("\nEnter the second integer: "); scanf("%d", &b);
    int sum = a + b;
    printf("\n The sum of %d and %d is : %d\n", a, b, sum);
    return 0;
}