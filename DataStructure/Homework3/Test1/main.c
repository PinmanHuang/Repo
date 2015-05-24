#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

int main() {
    NODE *t, *p;
    int f1Num, f2Num, searchInt, i;
    CONTACT profile[MaxMember];
    t = NULL;
    p = NULL;
    f1Num = CharToInt(profile);
    //讀入檔案的內容與數值
    for(int i=0; i<f1Num-2; i++) {
        //printf("%d - %s %d\n", i, profile[i].memString, profile[i].strInt);
        printf("%d - %d %s\n", i, profile[i].strInt, &profile[i].strInt);
    }
    printf("f1Num: %d\n", f1Num);
    //插入tree
    //printf("插入: ");
    for(i=0; i<f1Num-1; i++) {
        t = insertNode(profile[i].strInt, t);
        //printf("%d - %d\n", i, profile[i].strInt);
    }
    //printf(" into the tree \n\n");
    //display_avl(t);
    printf("search: ");
    scanf("%s", &searchInt);
    //printf("%d\n", searchInt);
    p = searchNode(searchInt, t);
    if(p == NULL)
        printf("不存在\n");
    else
        printf("存在: %s - %d\n", &searchInt, p->dataInt);
    disposeTree(t);
    return 0;
}
