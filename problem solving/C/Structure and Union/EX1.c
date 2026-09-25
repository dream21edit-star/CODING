#include <stdio.h>
#include <string.h>
typedef struct {
    char name[50];
    int roll_number;
    float percentage;
} Student;

int main() {
    Student S;
    printf("\nEnter Student Name: "); scanf("%s", S.name);
    printf("Enter Roll Number: "); scanf("%d", &S.roll_number);
    printf("Enter Percentage: "); scanf("%f", &S.percentage);
    printf("\n--- Student Details ---\n");
    printf("Name: %s\nRoll Number: %d\nPercentage: %.2f%%\n", S.name, S.roll_number, S.percentage);
    return 0;
}