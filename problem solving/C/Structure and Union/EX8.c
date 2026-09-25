#include <stdio.h>
typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
int comparision(Time t1, Time t2) {
        if(t1.hour==t2.hour && t1.minute==t2.minute && t1.second==t2.second) {
            printf("\nBoth Time structures represent the SAME time.\n");
            return 1;
        } else { 
            return 0; 
        }
    }

int main() {
    Time t[2];
    int i;
    for(i=0; i<2; i++) {
        printf("Enter Time %d (HH MM SS): ", i+1);
        scanf("%d %d %d", &t[i].hour, &t[i].minute, &t[i].second);
    }
    for(i=0; i<2; i++) comparision(t[i], t[i+1]);
    return 0;
}
