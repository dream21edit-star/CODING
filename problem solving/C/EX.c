#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char text[] = "Python";
int n = strlen(text);
char Reversed[n+1];
int j = 0;
for(int i = n-1; i>=0; i--) {
    Reversed[j] = text[i];
    j++;
}
Reversed[n] = '\0';
printf("Original: %s,\nReversed: %s\n", text, Reversed);
return 0;
} 