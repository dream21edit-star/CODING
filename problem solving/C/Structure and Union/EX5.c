#include <stdio.h>
typedef struct {
    float length;
    float width;
} Rectangle;
void calculate_properties(Rectangle R) {
    float L = R.length;
    float W = R.width;
    float area = L*W;
    float perimeter = 2*(L+W);
    printf("\n--- Rectangle properties---\n");
    printf("Area = %.2f\nPerimeter = %.2f\n", area, perimeter);
}

int main() {
    Rectangle R;
    printf("Enter length: "); scanf("%f", &R.length);
    printf("Enter width: "); scanf("%f", &R.width);
    calculate_properties(R);
    return 0;
}
