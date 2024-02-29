#ifdef  C_AND_CPP_CIRLINKLIST_H
#define C_AND_CPP_CIRLINKLIST_H
#endif //C_AND_CPP_CIRLINKLIST_H

#include "cirlinklistdef.h"
#include "arrsort.h"

void initiliaze(CirLinkList *list) {
    list->head = NULL;
    list->length = 0;
}

void distory(CirLinkList *list) {
    clear(list);
}

void clear(CirLinkList *list) {
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

bool isEmpty(CirLinkList *list) {
    return list->length == 0;
}

long long sizeOf(CirLinkList *list) {
    return list->length;
}

/*private:*/ struct Node *_get_node(CirLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return NULL;
    struct Node *t = list->head;
    for (long long i = 0; i < idx; ++i)
        t = t->next;
    return t;
}

ElemType getElem(CirLinkList *list, long long idx) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return -1;
    return t->data;
}

void setElem(CirLinkList *list, long long idx, ElemType elem) {
    struct Node *t = _get_node(list, idx);
    if (t == NULL)
        return;
    t->data = elem;
}

void addElem(CirLinkList *list, long long idx, ElemType elem) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    t->data = elem;
    if (idx == 0) {
        if (list->head == NULL) {
            list->head = t;
            t->next = t;
        } else {
            struct Node *last = list->head;
            while (last->next != list->head)
                last = last->next;
            t->next = list->head;
            list->head = t;
            last->next = t;
        }
    } else {
        struct Node *prev = _get_node(list, idx - 1);
        t->next = prev->next;
        prev->next = t;
    }
    ++list->length;
}

void removeElem(CirLinkList *list, long long idx) {
    if (idx < 0 || idx >= list->length)
        return;
    struct Node *t = NULL;
    if (idx == 0) {
        t = list->head;
        if (list->length == 1) {
            list->head = NULL;
        } else {
            struct Node *last = list->head;
            while (last->next != list->head)
                last = last->next;
            list->head = list->head->next;
            last->next = list->head;
        }
    } else {
        struct Node *prev = _get_node(list, idx - 1);
        t = prev->next;
        prev->next = t->next;
    }
    free(t);
    --list->length;
}

long long indexOf(CirLinkList *list, ElemType elem) {
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; ++i, t = t->next)
        if (t->data == elem)
            return i;
    return -1;
}

void printList(CirLinkList *list) {
    struct Node *t = list->head;
    while (t != NULL) {
        std::cout << t->data << " ";
        t = t->next;
        if (t == list->head)
            break;
    }
    std::cout << std::endl;
}

void reverseList(CirLinkList *list) {
    if (list->length <= 1)
        return;
    struct Node *temp = NULL, *new_head = NULL;
    struct Node *t = list->head;
    while (t->next != list->head) {
        temp = t;
        t = t->next;
        temp->next = new_head;
        new_head = temp;
    }
    list->head = new_head;
}

void sortList(CirLinkList *list) {
    if (list->length <= 1)
        return;
    ElemType *arr = (ElemType *)malloc(sizeof(ElemType) * list->length);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    struct Node *t = list->head;
    for (long long i = 0; i < list->length; ++i) {
        arr[i] = t->data;
        t = t->next;
    }
    mergeSort(arr, 0, list->length - 1);
    t = list->head;
    for (long long i = 0; i < list->length; ++i) {
        t->data = arr[i];
        t = t->next;
    }
    free(arr);
}
