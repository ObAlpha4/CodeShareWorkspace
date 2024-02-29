#ifndef C_AND_CPP_LINKLISTDEF_H
#define C_AND_CPP_LINKLISTDEF_H
#endif //C_AND_CPP_LINKLISTDEF_H

#include <iostream>

typedef int ElemType;
struct Node {
    ElemType data;
    struct Node *next;
};
typedef struct {
    struct Node *head;
    long long length;
} LinkList;

void initiliaze(LinkList *list);
void distory(LinkList *list);
void clear(LinkList *list);
bool isEmpty(LinkList *list);
long long sizeOf(LinkList *list);
ElemType getElem(LinkList *list, long long idx);
void setElem(LinkList *list, long long idx, ElemType elem);
void addElem(LinkList *list, long long idx, ElemType elem);
void removeElem(LinkList *list, long long idx);
long long indexOf(LinkList *list, ElemType elem);
void printList(LinkList *list);
void reverseList(LinkList *list);
void sortList(LinkList *list);
