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
    return 0;
}
