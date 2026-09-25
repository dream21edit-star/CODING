#include <stdio.h>
#define pi 3.14
#include <stdlib.h>
typedef struct {
    float radius;
    float area;
} Circle;

int main() {
    Circle *c = (Circle*)malloc(sizeof(Circle));
    float r = c->radius;
    float a = c->area;
    printf("Enter Circle Radius: "); scanf("%f", &r);
    a = pi*r*r;
    printf("\n--- Dynamic Circle Report ---\n");
    printf("Radius: %.2f\nArea: %.2f\n", r, a);
    free(c);
    return 0;
}