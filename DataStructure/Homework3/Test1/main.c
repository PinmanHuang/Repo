#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

int main() {
    int f1Num, f2Num;
    CONTACT profile[MaxMember];
    f1Num = CharToInt(profile);
    /*
    for(int i=0; i<f1Num-1; i++) {
        printf("%d - %d\n", i, profile[i].strInt);
    }
    printf("f1Num: %d\n", f1Num);
    */
    f2Num = CharToStr(profile);
    /*
    for(int i=0; i<f2Num-1; i++) {
        if(i%2 == 0) {
            printf("%d - %s\n", i, profile[i].memString);
        }
    }
    printf("f2Num: %d\n", f2Num);
    */
    return 0;
}
