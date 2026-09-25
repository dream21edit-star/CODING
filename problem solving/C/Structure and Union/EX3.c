#include <stdio.h>
#include <string.h>
typedef struct {
    char name[50];
    int roll_number;
    float percentage;
} Student;
int main() {
    Student S[3];
    int i;
    int max_i=0;
    for(i=0; i<3; i++) {
        printf("Enter details for Student %d:\n", i+1);
        printf("Name: "); scanf("%s", S[i].name);
        printf("Roll Number: "); scanf("%d", &S[i].roll_number);
        printf("Percentage: "); scanf("%f", &S[i].percentage);
        printf("\n");
        if(S[i].percentage > S[max_i].percentage) max_i = i;
    }
    printf("--- Student with Highest Percentage ---\n");
    printf("Name: %s\n", S[max_i].name);
    printf("Percentage: %.2f%%\n", S[max_i].percentage);
    return 0;
}