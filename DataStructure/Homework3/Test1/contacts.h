//__CONTACTS_H__
#ifndef __CONTACTS_H__
#define __CONTACTS_H__
#define MaxMember 96

//通訊錄結構
struct contact{
    int strInt;
    char memString[7];
	int phoneNum;
};

//AVLTree結構
struct node {
	char *nameStr;
    int dataInt;
	int phoneNum;
    struct node* left;
    struct node* right;
    int height;
};

//讀檔
typedef struct contact CONTACT;
typedef struct node NODE;

//AVLTree
extern int CharToInt(CONTACT*);
extern int CharToStr(CONTACT*);
extern void disposeTree(NODE*);
extern NODE* searchNode(int, NODE*);
extern NODE* find_min(NODE*);
extern NODE* find_max(NODE*);
extern NODE* insertNode(int, char*, int, NODE*);
extern NODE* delete(int, NODE*);
extern void display_avl(NODE*);
extern int getNode(NODE*);
extern void inorder(NODE*);
extern void preorder(NODE*);
extern void postorder(NODE*);
#endif
