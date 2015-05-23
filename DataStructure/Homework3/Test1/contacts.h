//__CONTACTS_H__
#ifndef __CONTACTS_H__
#define __CONTACTS_H__
#define MaxMember 94
struct contact{
    int strInt;
    char string[7];
};
typedef struct contact CONTACT;

extern int CharToInt(CONTACT*);
extern int CharToStr(CONTACT*);
#endif
