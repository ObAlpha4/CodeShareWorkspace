#ifndef C_AND_CPP_LINKLIST_H
#define C_AND_CPP_LINKLIST_H
#endif //C_AND_CPP_LINKLIST_H

#include "linklistdef.h"
#include "arrsort.h"

void initiliaze(LinkList *list) {
    list->head = NULL;
    list->length = 0;
}

void distory(LinkList *list) {
    clear(list);
}

void clear(LinkList *list) {
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

bool isEmpty(LinkList *list) {
    return list->length == 0;
}

long long sizeOf(LinkList *list) {
    return list->length;
}

/*private:*/ struct Node *_get_node(LinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return NULL;
    struct Node *t = list->head;
    for (long long i = 0; i < idx; ++i)
        t = t->next;
    return t;
}

ElemType getElem(LinkList *list, long long idx) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return -1;
    return t->data;
}

void setElem(LinkList *list, long long idx, ElemType elem) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return;
    t->data = elem;
}

void addElem(LinkList *list, long long idx, ElemType elem) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = elem;
    if (idx == 0) {
        t->next = list->head;
        list->head = t;
    } else {
        struct Node *p = _get_node(list, idx - 1);
        t->next = p->next;
        p->next = t;
    }
    ++list->length;
}

void removeElem(LinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = NULL;
    if (idx == 0) {
        t = list->head;
        list->head = list->head->next;
    } else {
        struct Node *temp = _get_node(list, idx - 1);
        t = temp->next;
        temp->next = t->next;
    }
    free(t);
    --list->length;
}

long long indexOf(LinkList *list, ElemType elem) {
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; i++) {
        if (t->data == elem)
            return i;
        t = t->next;
    }
    return -1;
}

void printList(LinkList *list) {
    struct Node *t = list->head;
    while (t != NULL) {
        std::cout << t->data << " ";
        t = t->next;
    }
    std::cout << std::endl;
}

void reverseList(LinkList *list) {
    if (list->length <= 1)
        return;
    struct Node *temp = NULL, *new_head = NULL;
    while (list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        temp->next = new_head;
        new_head = temp;
    }
    list->head = new_head;
}

void sortList(LinkList *list) {
    if (list->length <= 1)
        return;
    ElemType *arr = (ElemType *) malloc(sizeof(ElemType) * list->length);
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; i++) {
        arr[i] = t->data;
        t = t->next;
    }
    mergeSort(arr, 0, list->length - 1);
    t = list->head;
    for (long long i = 0; i < list->length; i++) {
        t->data = arr[i];
        t = t->next;
    }
    free(arr);
}
