#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

//將字串以數值存取->比較大小
int CharToInt(CONTACT profile[MaxMember]) {
    int memNum=0;
    FILE *fptr = fopen("contacts.txt", "r");
    while(!feof(fptr)) {
        fscanf(fptr, "%s", &profile[memNum].strInt);
    printf("%d - %d\n", memNum, profile[memNum].strInt);
    memNum++;
    }
    printf("memNum: %d\n", memNum);
    return memNum;
}
