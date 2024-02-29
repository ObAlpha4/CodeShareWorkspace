#ifdef C_AND_CPP_CIRLINKLIST_H
#define C_AND_CPP_CIRLINKLIST_H
#endif //C_AND_CPP_CIRLINKLIST_H

#include <iostream>

typedef int ElemType;
struct Node {
    ElemType data;
    struct Node *next;
};
typedef struct {
    struct Node *head;
    long long length;
} CirLinkList;

void initiliaze(CirLinkList *list);
void distory(CirLinkList *list);
void clear(CirLinkList *list);
bool isEmpty(CirLinkList *list);
long long sizeOf(CirLinkList *list);
ElemType getElem(CirLinkList *list, long long idx);
void setElem(CirLinkList *list, long long idx, ElemType elem);
void addElem(CirLinkList *list, long long idx, ElemType elem);
void removeElem(CirLinkList *list, long long idx);
long long indexOf(CirLinkList *list, ElemType elem);
void printList(CirLinkList *list);
void reverseList(CirLinkList *list);
void sortList(CirLinkList *list);
