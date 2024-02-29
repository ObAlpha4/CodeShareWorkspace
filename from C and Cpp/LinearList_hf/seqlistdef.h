#ifndef C_AND_CPP_SEQLISTDEF_H
#define C_AND_CPP_SEQLISTDEF_H
#endif //C_AND_CPP_SEQLISTDEF_H

#include <iostream>

typedef int ElemType;
typedef struct {
    ElemType *data;
    long long length;
    long long size;
} SeqList;

void initiliaze(SeqList *list, long long size);
void destory(SeqList *list);
void clear(SeqList *list);
bool isEmpty(SeqList *list);
long long sizeOf(SeqList *list);
ElemType getElem(SeqList *list, long long idx);
void setElem(SeqList *list, long long idx, ElemType elem);
void addElem(SeqList *list, long long idx, ElemType elem);
void removeElem(SeqList *list, long long idx);
long long indexOf(SeqList *list, ElemType elem);
void printList(SeqList *list);
void reverseList(SeqList *list);
void sortList(SeqList *list);
