#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

int main() {
    NODE *t, *p;
    int f1Num, f2Num, searchInt, i;
    CONTACT profile[MaxMember], nameStr[MaxMember];
    t = NULL;
    p = NULL;
    //NameToNum輸出檔案以供名子與數值做對照
    FILE *fptr = fopen("NameToNum.txt", "w");
    f1Num = CharToInt(profile);
	f2Num = CharToStr(nameStr);
    //輸出檔案的內容與數值
    for(int i=1; i<f1Num-1; i++) {
        fprintf(fptr, "%d %d %s\n", i, profile[i].strInt, &profile[i].strInt);
	}
    fclose(fptr);
    //插入tree
    for(i=1; i<f1Num-1; i++) {
        t = insertNode(profile[i].strInt, nameStr[i].memString, nameStr[i].phoneNum, t);
    }
    display_avl(t);
	printf("\n***Inorder***\n");
	inorder(t);
	printf("\n***Preorder***\n");
	preorder(t);
    printf("\nsearch: ");
    scanf("%s", &searchInt);
    p = searchNode(searchInt, t);
    if(p == NULL)
        printf("不存在\n");
    else
        printf("存在: %s (%d)\n", &searchInt, p->phoneNum);
    disposeTree(t);
    return 0;
}
