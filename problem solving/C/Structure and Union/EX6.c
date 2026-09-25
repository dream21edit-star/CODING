#include <stdio.h>

// 1. Structure Definition
struct Rectangle {
    float length;
    float width;
    float area;
};

// 2. Function that returns a structure
struct Rectangle get_rectangle_data() {
    struct Rectangle r;

    printf("Enter Length of Rectangle: ");
    scanf("%f", &r.length);
    printf("Enter Width of Rectangle: ");
    scanf("%f", &r.width);

    // Calculate Area
    r.area = r.length * r.width;

    return r; // Returns the entire structure
}

int main() {
    // 3. Call the function and store the returned structure
    struct Rectangle r1 = get_rectangle_data();

    printf("\n--- Rectangle Report ---\n");
    printf("Length: %.2f\n", r1.length);
    printf("Width: %.2f\n", r1.width);
    printf("Calculated Area: %.2f\n", r1.area);

    return 0;
}