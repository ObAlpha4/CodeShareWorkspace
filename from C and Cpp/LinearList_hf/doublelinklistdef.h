#ifdef C_AND_CPP_DOUBLELINKLISTDEF_H
#define C_AND_CPP_DOUBLELINKLISTDEF_H
#endif //C_AND_CPP_DOUBLELINKLISTDEF_H

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
} DoubleLinkList;

void initiliaze(DoubleLinkList *list);
void distory(DoubleLinkList *list);
void clear(DoubleLinkList *list);
bool isEmpty(DoubleLinkList *list);
long long sizeOf(DoubleLinkList *list);
ElemType getElem(DoubleLinkList *list, long long idx);
void setElem(DoubleLinkList *list, long long idx, ElemType elem);
void addElem(DoubleLinkList *list, long long idx, ElemType elem);
void removeElem(DoubleLinkList *list, long long idx);
long long indexOf(DoubleLinkList *list, ElemType elem);
void printList(DoubleLinkList *list);
void reverseList(DoubleLinkList *list);
void sortList(DoubleLinkList *list);
