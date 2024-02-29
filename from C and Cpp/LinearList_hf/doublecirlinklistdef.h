#ifdef C_AND_CPP_DOUBLECIRLINKLIST_H
#define C_AND_CPP_DOUBLECIRLINKLIST_H
#endif //C_AND_CPP_DOUBLECIRLINKLIST_H

#include <iostream>

typedef int ElemType;
struct Node {
    ElemType data;
    struct Node *prev;
    struct Node *next;
};
typedef struct {
    struct Node *head;
    long long length;
} DoubleCirLinkList;

void initiliaze(DoubleCirLinkList *list);
void distory(DoubleCirLinkList *list);
void clear(DoubleCirLinkList *list);
bool isEmpty(DoubleCirLinkList *list);
long long sizeOf(DoubleCirLinkList *list);
ElemType getElem(DoubleCirLinkList *list, long long idx);
void setElem(DoubleCirLinkList *list, long long idx, ElemType elem);
void addElem(DoubleCirLinkList *list, long long idx, ElemType elem);
void removeElem(DoubleCirLinkList *list, long long idx);
long long indexOf(DoubleCirLinkList *list, ElemType elem);
void printList(DoubleCirLinkList *list);
void reverseList(DoubleCirLinkList *list);
void sortList(DoubleCirLinkList *list);
