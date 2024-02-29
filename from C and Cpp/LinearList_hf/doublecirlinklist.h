#ifdef C_AND_CPP_DOUBLECIRLINKLIST_H
#define C_AND_CPP_DOUBLECIRLINKLIST_H
#endif //C_AND_CPP_DOUBLECIRLINKLIST_H

#include "doublecirlinklistdef.h"
#include "arrsort.h"

void initiliaze(DoubleCirLinkList *list) {
    list->head = NULL;
    list->length = 0;
}

void distory(DoubleCirLinkList *list) {
    clear(list);
}

void clear(DoubleCirLinkList *list) {
    if (list->head == NULL)
        return;
    struct Node *t = list->head;
    while (t->next != list->head) {
        list->head = t->next;
        free(t);
        t = list->head;
    }
    free(t);
    list->head = NULL;
    list->length = 0;
}

bool isEmpty(DoubleCirLinkList *list) {
    return list->length == 0;
}

long long sizeOf(DoubleCirLinkList *list) {
    return list->length;
}

/*private:*/ struct Node *_get_node(DoubleCirLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return NULL;
    struct Node *t = list->head;
    for (long long i = 0; i < idx; ++i)
        t = t->next;
    return t;
}

ElemType getElem(DoubleCirLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return -1;
    struct Node *t = list->head;
    for (long long i = 0; i < idx; i++)
        t = t->next;
    return t->data;
}

void setElem(DoubleCirLinkList *list, long long idx, ElemType elem) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return;
    t->data = elem;
}

void addElem(DoubleCirLinkList *list, long long idx, ElemType elem) {
    if (idx < 0 || idx > list->length)
        return;
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = elem;
    if (idx == 0) {
        if (list->head == NULL) {
            list->head = t;
            t->next = t;
            t->prev = t;
        } else {
            t->next = list->head;
            t->prev = list->head->prev;
            list->head->prev->next = t;
            list->head->prev = t;
            list->head = t;
        }
    } else {
        struct Node *temp = _get_node(list, idx - 1);
        t->next = temp->next;
        t->prev = temp;
        temp->next->prev = t;
        temp->next = t;
    }
    ++list->length;
}

void removeElem(DoubleCirLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = NULL;
    if (idx == 0) {
        t = list->head;
        list->head = list->head->next;
        list->head->prev = t->prev;
        t->prev->next = list->head;
    } else {
        struct Node *temp = _get_node(list, idx - 1);
        t = temp->next;
        temp->next = t->next;
        t->next->prev = temp;
    }
    free(t);
    --list->length;
}

long long indexOf(DoubleCirLinkList *list, ElemType elem) {
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; i++) {
        if (t->data == elem)
            return i;
        t = t->next;
    }
    return -1;
}

void printList(DoubleCirLinkList *list) {
    struct Node *t = list->head;
    while (t != NULL) {
        std::cout << t->data << " ";
        t = t->next;
        if (t == list->head)
            break;
    }
    std::cout << std::endl;
}

void reverseList(DoubleCirLinkList *list) {
    if (list->length <= 1)
        return;
    struct Node *p = list->head, *q = list->head->next;
    while (q != list->head) {
        p->next = q->next;
        q->prev = NULL;
        q->next = list->head;
        list->head->prev = q;
        list->head = q;
        q = p->next;
    }
}

void sortList(DoubleCirLinkList *list) {
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
