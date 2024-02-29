#include <iostream>
using namespace std;

typedef struct {
    long n;
    char begin, mid, end;
} Data;
struct Node {
    Data item;
    struct Node *next;
};
typedef struct {
    struct Node *base;
    size_t top;
} Stack;

void pop(Stack *s);
void push(Stack *s, long n, char begin, char mid, char end);
void hanoi(long n, char begin, char mid, char end);

int main() {
    long t;
    cin >> t;
    hanoi(t, 'a', 'b', 'c');
    return 0;
}

void pop(Stack *s) {
    if (s->top == 0)
        return;
    else {
        struct Node *t = s->base;
        s->base = s->base->next;
        free(t);
        --s->top;
    }
}

void push(Stack *s, long n, char begin, char mid, char end) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->item.n = n;
    t->item.begin = begin;
    t->item.mid = mid;
    t->item.end = end;
    t->next = s->base;
    s->base = t;
    ++s->top;
}

void hanoi(long n, char begin, char mid, char end) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->base = (struct Node *) malloc(sizeof(struct Node));
    s->top = 0;
    push(s, n, begin, mid, end);
    while (s->top != 0) {
        Data up = s->base->item;
        pop(s);
        if (up.n == 1) {
            printf("%c -> %c\n", up.begin, up.end);
        } else {
            push(s, up.n - 1, up.mid, up.begin, up.end);
            push(s, 1, up.begin, up.mid, up.end);
            push(s, up.n - 1, up.begin, up.end, up.mid);
        }
    }
    free(s);
}