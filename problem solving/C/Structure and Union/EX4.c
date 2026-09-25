#include <stdio.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;
typedef struct {
    int id;
    char name[50];
    Date joining_date;
} Employee;

int main() {
    Employee E;
    printf("Enter Employee ID: "); scanf("%d", &E.id);
    printf("Enter Employee Name: "); scanf("%s", E.name);
    printf("Enter Joining Day (DD): "); scanf("%d", &E.joining_date.day);
    printf("Enter Joining Month (MM): "); scanf("%d", &E.joining_date.month);
    printf("Enter Joining Year (YYYY): "); scanf("%d", &E.joining_date.year);
    printf("\n--- Employee Details ---\n");
    printf("ID: %d\nName: %s\nJoining Date: %d/%d/%d\n", 
        E.id, E.name, E.joining_date.day, E.joining_date.month, 
        E.joining_date.year);
    return 0;
}