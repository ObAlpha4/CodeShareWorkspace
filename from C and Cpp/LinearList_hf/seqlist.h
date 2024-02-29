#ifndef C_AND_CPP_SEQLIST_H
#define C_AND_CPP_SEQLIST_H
#endif //C_AND_CPP_SEQLIST_H

#include "seqlistdef.h"
#include "arrsort.h"

void initiliaze(SeqList *list, long long size) {
    list->size = size;
    list->data = (ElemType *) malloc(list->size * sizeof(ElemType));
    if (list->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(-1);
    }
    list->length = 0;
}

void destory(SeqList *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->length = 0;
}

void clear(SeqList *list) {
    if (list->length == 0)
        return;
    list->length = 0;
}

bool isEmpty(SeqList *list) {
    return list->length == 0;
}

long long sizeOf(SeqList *list) {
    return list->length;
}

ElemType getElem(SeqList *list, long long idx) {
    return list->data[idx];
}

void setElem(SeqList *list, long long idx, ElemType elem) {
    if (list == NULL || idx < 0 || idx > list->length)
        return;
    list->data[idx] = elem;
}

void addElem(SeqList *list, long long idx, ElemType elem) {
    if (list == NULL || idx < 0 || idx > list->length)
        return;
    ElemType *temp = list->data;
    if (list->size < list->length + 1) {
        list->size *= 2;
        temp = (ElemType *) malloc(list->size * sizeof(ElemType));
        for (long long i = 0; i < idx; ++i) {
            temp[i] = list->data[i];
        }
    }
    for (long long i = list->length; i > idx; --i) {
        temp[i] = list->data[i - 1];
    }
    temp[idx] = elem;
    if (temp != list->data) {
        free(list->data);
        list->data = temp;
    }
    ++list->length;
}

void removeElem(SeqList *list, long long idx) {
    if (list == NULL || idx < 0 || idx > list->length)
        return;
    for (long long i = idx + 1; i < list->length; ++i)
        list->data[i - 1] = list->data[i];
    --list->length;
}

long long indexOf(SeqList *list, ElemType elem) {
    for (long long i = 0; i < list->length; ++i)
        if (list->data[i] == elem)
            return i;
    return -1;
}

void printList(SeqList *list) {
    for (long long i = 0; i < list->length; ++i)
        std::cout << list->data[i] << " ";
    std::cout << std::endl;
}

void reverseList(SeqList *list) {
    for (long long i = 0; i < list->length / 2; ++i) {
        ElemType temp = list->data[i];
        list->data[i] = list->data[list->length - i - 1];
        list->data[list->length - i - 1] = temp;
    }
}

void sortList(SeqList *list) {
    mergeSort(list->data, 0, list->length - 1);
}
