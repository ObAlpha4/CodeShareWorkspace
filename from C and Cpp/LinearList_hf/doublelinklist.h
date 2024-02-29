#ifdef C_AND_CPP_DOUBLELINKLIST_H
#define C_AND_CPP_DOUBLELINKLIST_H
#endif //C_AND_CPP_DOUBLELINKLIST_H

#include "doublelinklistdef.h"
#include "arrsort.h"

void initiliaze(DoubleLinkList *list) {
    list->head = NULL;
    list->length = 0;
}

void distory(DoubleLinkList *list) {
    clear(list);
}

void clear(DoubleLinkList *list) {
    if (list->head == NULL)
        return;
    struct Node *t = list->head;
    while (t != NULL) {
        list->head = t->next;
        free(t);
        t = list->head;
    }
    free(t);
    list->head = NULL;
    list->length = 0;
}

bool isEmpty(DoubleLinkList *list) {
    return list->length == 0;
}

long long sizeOf(DoubleLinkList *list) {
    return list->length;
}

/*private:*/ struct Node *_get_node(DoubleLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return NULL;
    struct Node *t = list->head;
    for (long long i = 0; i < idx; ++i)
        t = t->next;
    return t;
}

ElemType getElem(DoubleLinkList *list, long long idx) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return -1;
    return t->data;
}

void setElem(DoubleLinkList *list, long long idx, ElemType elem) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return;
    t->data = elem;
}

void addElem(DoubleLinkList *list, long long idx, ElemType elem) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = elem;
    if (idx == 0) {
        t->next = list->head;
        t->prev = NULL;
        if (list->head != NULL)
            list->head->prev = t;
        list->head = t;
    } else {
        struct Node *p = _get_node(list, idx - 1);
        t->next = p->next;
        t->prev = p;
        p->next = t;
        if (t->next != NULL)
            t->next->prev = t;
    }
    ++list->length;
}

void removeElem(DoubleLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = NULL;
    if (idx == 0) {
        t = list->head;
        list->head = t->next;
        if (list->head != NULL)
            list->head->prev = NULL;
    } else {
        struct Node *p = _get_node(list, idx - 1);
        t = p->next;
        p->next = t->next;
        if (t->next != NULL)
            t->next->prev = p;
    }
    free(t);
    --list->length;
}

long long indexOf(DoubleLinkList *list, ElemType elem) {
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; ++i, t = t->next)
        if (t->data == elem && i < list->length)
            return i;
    return -1;
}

void printList(DoubleLinkList *list) {
    struct Node *t = list->head;
    while (t != NULL) {
        std::cout << t->data << " ";
        t = t->next;
    }
    std::cout << std::endl;
}

void reverseList(DoubleLinkList *list) {
    if (list->length <= 1)
        return;
    struct Node *p = list->head, *q = list->head->next;
    while (q != NULL) {
        p->next = q->next;
        q->prev = NULL;
        q->next = list->head;
        list->head->prev = q;
        list->head = q;
        q = p->next;
    }
}

void sortList(DoubleLinkList *list) {
    if (list->length <= 1)
        return;
    ElemType *arr = (ElemType *) malloc(sizeof(ElemType) * list->length);
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; ++i, t = t->next)
        arr[i] = t->data;
    mergeSort(arr, 0, list->length - 1);
    t = list->head;
    for (long long i = 0; i < list->length; ++i, t = t->next)
        t->data = arr[i];
    free(arr);
}
