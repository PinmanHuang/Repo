#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

//釋放空間
void disposeTree(NODE *t) {
    if(t != NULL) {
        disposeTree(t -> left);
        disposeTree(t -> right);
        free(t);
    }
}

//搜尋,回傳值的位址
NODE* searchNode(int dataInt, NODE *t) {
    if(t == NULL)
        return NULL;
    if(dataInt < t->dataInt)
        return searchNode(dataInt, t->left);
    else if(dataInt > t->dataInt)
        return searchNode(dataInt, t->right);
    else
        return t;
}

NODE* find_min(NODE *t) {
    if(t==NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return find_min(t->left);
}

NODE* find_max(NODE *t) {
    if(t != NULL) {
        while(t->right != NULL)
            t = t->right;
    }
    return t;
}

//NODE高度
static int height(NODE *n) {
    if(n == NULL)
        return -1;
    else
        return n->height;
}

//比較兩個值取大的
static int max(int l, int r) {
    return l > r ? l : r;
}

//當NODE(k2)有左兒子時,旋轉
static NODE* single_rotate_with_left(NODE *k2) {
    NODE *k1 = NULL;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right))+1;
    k1->height = max(height(k1->left), k2->height)+1;
    return k1;
}

//當NODE(k1)有右兒子時,旋轉
static NODE* single_rotate_with_right(NODE *k1) {
    NODE *k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right))+1;
    k2->height = max(height(k2->right), k1->height)+1;
    return k2;
}

//當NODE(k3)有左兒子且其左兒子有右兒子,旋轉兩次
static NODE* double_rotate_with_left(NODE *k3) {
    //k1 k2旋轉
    k3->left = single_rotate_with_right(k3->left);
    //k3 k2旋轉
    return single_rotate_with_left(k3);
}

//當NODE(k1)有右兒子且其右兒子有左兒子,旋轉兩次
static NODE* double_rotate_with_right(NODE *k1) {
    //k3 k2旋轉
    k1->right = single_rotate_with_left(k1->right);
    //k1 k2旋轉
    return single_rotate_with_right(k1);
}

//插入新節點
NODE* insertNode(int strInt, NODE *t) {
    if(t == NULL) {
        t = (NODE*)malloc(sizeof(NODE));
        if(t==NULL) {
            fprintf(stderr, "Out of memory!!!(insert)\n");
            exit(1);
        }
        else {
            t->dataInt = strInt;
            t->height = 0;
            t->left = t->right = NULL;
        }
    }
    else if(strInt < t->dataInt) {
        t->left = insertNode(strInt, t->left);
        if(height(t->left) - height(t->right) == 2) {
            if(strInt < t->left->dataInt)
                t = single_rotate_with_left(t);
            else
                t = double_rotate_with_left(t);
        }
    }
    else if(strInt > t->dataInt) {
        t->right = insertNode(strInt, t->right);
        if(height(t->right) - height(t->left) == 2) {
            if(strInt > t->right->dataInt)
                t = single_rotate_with_right(t);
            else
                t = double_rotate_with_right(t);
        }
    }
    t->height = max(height(t->left), height(t->right))+1;
    return t;
}

//刪除節點,尚未實做
NODE* delete(int strInt, NODE *t) {
    return t;
}

//取得節點資料
int getNode(NODE *n) {
    return n->dataInt;
}

//展現術結構
void display_avl(NODE *t) {
    if(t == NULL)
        return;
    printf("%d", t->dataInt);
    if(t->left != NULL)
        printf("(左：%d)", t->left->dataInt);
    if(t->right != NULL)
        printf("(右: %d)", t->right->dataInt);
    printf("\n");

    display_avl(t->left);
    display_avl(t->right);
}
