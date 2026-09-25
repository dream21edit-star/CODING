#include <stdio.h>
int main() {
    int a = 0, b = 20;
    float division = b/a;
    if(a!=0) printf("Quotient: %d/%d = %.2f\n", b, a, division);
    else printf("wtf dude a=0?\n");
    return 0;
}