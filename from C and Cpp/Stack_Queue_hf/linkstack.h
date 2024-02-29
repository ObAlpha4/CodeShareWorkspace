#ifndef C_AND_CPP_LINKSTACK_H
#define C_AND_CPP_LINKSTACK_H
#endif //C_AND_CPP_LINKSTACK_H

#include "linkstackdef.h"

void initlize(LinkStack *stack) {
    stack->base = (struct Node *) malloc(sizeof(struct Node));
    stack->top = 0;
}

void pop(LinkStack *stack) {
    if (stack->top == 0)
        return;
    else {
        struct Node *t = stack->base;
        stack->base = stack->base->next;
        free(t);
        --stack->top;
    }
}

void push(LinkStack *stack, ElemType elem) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = elem;
    t->next = stack->base;
    stack->base = t;
    ++stack->top;
}

bool isEmpty(LinkStack *stack) {
    return stack->top == 0;
}

ElemType getTop(LinkStack *stack) {
    return stack->base->data;
}
