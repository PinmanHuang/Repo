#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

//將字串以數值存取->比較大小
int CharToInt(CONTACT profile[MaxMember]) {
    int memNum=0;
    FILE *fptr = fopen("contacts.txt", "r");
    if(fptr == NULL) {
        printf("File not exist.\n");
        exit(EXIT_FAILURE);
    }
    while(!feof(fptr)) {
        fscanf(fptr, "%s", &profile[memNum].strInt);
        //印出每一筆資料對應數值
        //printf("%d - %d\n", memNum, profile[memNum].strInt);
        memNum++;
    }
    fclose(fptr);
    //printf("memNum: %d\n", memNum);
    return memNum;
}

//將字元以自傳存取
int CharToStr(CONTACT profile[MaxMember]) {
    int memNum=0;
    FILE *fptr = fopen("contacts.txt", "r");
    if(fptr == NULL) {
        printf("File not exist.\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(profile[memNum].memString, 50, fptr)) {
        //printf("%d - %s", memNum, profile[memNum].memString);
        memNum++;
    }
    fclose(fptr);
    //printf("memNum2: %d\n", memNum);
    return memNum;
}
