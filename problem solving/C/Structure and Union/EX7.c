#include <stdio.h>
typedef struct Car {
    int model_year;
    char color[50];
} Car;
int main() {
    Car A;
    Car *P = &A;
    printf("Enter Car Model Year: "); scanf("%d", &P->model_year);
    printf("Enter Car Color: "); scanf("%s", P->color);
    printf("\n--- Car Details (via Pointer) ---\n");
    
    printf("Model Year: %d\nColor: %s\n", P->model_year, P->color);
    return 0;
}