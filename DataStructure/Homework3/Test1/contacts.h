//__CONTACTS_H__
#ifndef __CONTACTS_H__
#define __CONTACTS_H__
#define MaxMember 94

//通訊錄結構
struct contact{
    int strInt;
    char memString[7];
};

//AVLTree結構
struct node {
    int dataInt;
    struct node* left;
    struct node* right;
    int height;
};

typedef struct contact CONTACT;
typedef struct node NODE;

extern int CharToInt(CONTACT*);
extern int CharToStr(CONTACT*);
extern void disposeTree(NODE*);
extern NODE* searchNode(int, NODE*);
extern NODE* find_min(NODE*);
extern NODE* find_max(NODE*);
extern NODE* insertNode(int, NODE*);
extern NODE* delete(int, NODE*);
extern void display_avl(NODE*);
extern int getNode(NODE*);
#endif
