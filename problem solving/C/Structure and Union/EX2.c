#include <stdio.h>
typedef struct {
    char title[100];
    char author[100];
    int pages;
    float price;
} Book;

int main() {
    Book B = {
        "The C Programming Language",
        "Dennis Ritchie",
        272,
        12.50
    };
    printf("\n--- Book Details ---\n");
    printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: $%.2f\n", B.title, B.author, B.pages, B.price);
    return 0;
}
