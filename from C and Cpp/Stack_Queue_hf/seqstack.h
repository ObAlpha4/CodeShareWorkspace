#ifndef C_AND_CPP_SEQSTACK_H
#define C_AND_CPP_SEQSTACK_H
#endif //C_AND_CPP_SEQSTACK_H

#include "seqstackdef.h"

void initlize(SeqStack *stack, long long size) {
    stack->base = (List *) malloc(sizeof(List));
    stack->top = 0;
    stack->base->data = (ElemType *) malloc(size * sizeof(ElemType));
    stack->base->size = size;
}

void pop(SeqStack *stack) {
    if (stack->top == 0)
        return;
    else
        --stack->top;
}

void push(SeqStack *stack, ElemType elem) {
    if (stack->top - 1 < stack->base->size) {
        stack->base->size *= 2;
        ElemType *temp = (ElemType *) malloc(stack->base->size * sizeof(ElemType));
        for (long long i = 0; i < stack->top; ++i) {
            temp[i] = stack->base->data[i];
        }
        free(stack->base->data);
        stack->base->data = temp;
    }
    stack->base->data[stack->top++] = elem;
}

bool isEmpty(SeqStack *stack) {
    return stack->top == 0;
}

ElemType getTop(SeqStack *stack) {
    return stack->base->data[stack->top - 1];
}
