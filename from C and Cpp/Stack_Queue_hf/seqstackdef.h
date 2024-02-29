#ifndef C_AND_CPP_SEQSTACKDEF_H
#define C_AND_CPP_SEQSTACKDEF_H
#endif //C_AND_CPP_SEQSTACKDEF_H

#include <iostream>

typedef int ElemType;
typedef struct {
    ElemType *data;
    long long size;
} List;
typedef struct {
    List *base;
    long long top;
} SeqStack;

void initlize(SeqStack *stack, long long size);
void pop(SeqStack *stack);
void push(SeqStack *stack, ElemType elem);
bool isEmpty(SeqStack *stack);
ElemType getTop(SeqStack *stack);
