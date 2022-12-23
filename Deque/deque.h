#ifndef DEQUE_H
#define DEQUE_H

typedef enum {false, true} bool;

typedef struct node {
    int element;
    struct node *previous, *next;
} Node;

typedef struct deque {
    Node *front, *rear;
    unsigned quantity;
} Deque;

Deque* initialize();
void destroy(Deque *d);
int is_empty(Deque *d);
unsigned size(Deque *d);
void push_front(Deque *d, int data);
void push_rear(Deque *d, int data);
int pop_front(Deque *d);
int pop_rear(Deque *d);
int get_front(Deque *d);
int get_rear(Deque *d);
void clear(Deque *d);
void print(Deque *d, bool front_to_rear);
void print_front_to_rear(Deque *d);
void print_rear_to_front(Deque *d);

#endif // DEQUE_H