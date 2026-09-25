#include <stdio.h>
#include <stdlib.h>
int main() {
    int *p1 = malloc(2 * sizeof(*p1));
    char *p2;
    float *p3;
    printf("Size of int pointer (int *): %zu bytes\n", sizeof(p1));
    printf("Size of char pointer (char *): %zu bytes\n", sizeof(p2));
    printf("Size of float pointer (float *): %zu bytes\n\n", sizeof(p3));
    printf("Size of 'int' variable: %zu bytes\n", sizeof(int));
    printf("Size of 'float' variable: %zu bytes\n", sizeof(float));

    char c = 'A';
    char *ptr_c = &c;

    double d = 3.14;
    double *ptr_d = &d;

    // Comparaison pour char
    printf("Taille de la variable char : %zu octet\n", sizeof(c));     // Affiche 1
    printf("Taille du pointeur char*   : %zu octets\n\n", sizeof(ptr_c)); // Affiche 4

    // Comparaison pour double
    printf("Taille de la variable double : %zu octets\n", sizeof(d));    // Affiche 8
    printf("Taille du pointeur double*   : %zu octets\n", sizeof(ptr_d)); // Affiche 4
    
    return 0;
}



