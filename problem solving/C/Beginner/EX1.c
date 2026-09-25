#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    float a;
    printf("Enter a floating-point number (e.g., 3.14159): ");
    scanf("%f", &a);
    printf("The number rounded to two decimal places is: %.2f\n", a);
    return 0;
}