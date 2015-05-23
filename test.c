#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#define profileNum 94

//通訊錄內容
struct contact {
    int strInt;
    char *line; //通訊錄人名
    size_t len;
};
typedef struct contact CONTACT;
CONTACT profile[profileNum];

int main() {
    //初始化line
    for(int i=0; i<profileNum; i++) {
        profile[i].line = (char *)malloc(7);
        profile[i].len = 7;
    }
    ssize_t read;
    FILE *inFilePtr1, *inFilePtr2;
    int f1Member=0, f2Member=0;
    //將名字存成數值->比大小
    inFilePtr1 = fopen("contacts.txt", "r");
    while(!feof(inFilePtr1)) {
        fscanf(inFilePtr1, "%s", &profile[f1Member].strInt);
        //printf("%d \n", f1Member);
        f1Member++;
    }

    printf("f1Member: %d\n", f1Member);
    /*
    //每一筆資料姓名對應數值
    for(int i=0; i<f1Member; i++) {
        printf("1-%d: %d\n", i, profile[i].strInt);
    }
    */
    
    //將名字存成字元串
    inFilePtr2 = fopen("contacts.txt", "r");
    /*
    while((read = getline(&profile[f2Member].line, &profile[f2Member].len, inFilePtr2)) != -1) {
        printf("%d - %s\n", f2Member, profile[f2Member].line);
        f2Member++;
        printf("%d\n", f2Member);
    }
    */
    printf("壞掉");
    while(fgets(profile[f2Member].line, 7, inFilePtr2) != NULL) {
        printf("%d\n", f2Member);
        f2Member++;
    }
    //printf("94: %s\n", profile[93].line);
    //printf("f2Member: %d\n", f2Member);
    for(int i=0; i<f2Member; i++) {
        printf("釋放line");
        free(profile[i].line);
    }
    fclose(inFilePtr1);
    fclose(inFilePtr2);
    return 0;
}
