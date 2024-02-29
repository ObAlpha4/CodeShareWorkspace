#ifndef C_AND_CPP_LINKSTACKDEF_H
#define C_AND_CPP_LINKSTACKDEF_H
#endif //C_AND_CPP_LINKSTACKDEF_H

#include <iostream>

typedef int ElemType;
struct Node {
    ElemType data;
    struct Node *next;
};
typedef struct {
    struct Node *base;
    long long top;
} LinkStack;

void initlize(LinkStack *stack);
void pop(LinkStack *stack);
void push(LinkStack *stack, ElemType elem);
bool isEmpty(LinkStack *stack);
ElemType getTop(LinkStack *stack);
