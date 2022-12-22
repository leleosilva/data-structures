#ifndef QUEUE_H
#define QUEUE_H

typedef struct node {
    int element;
    struct node *next;
} Node;

typedef struct queue {
    Node *front, *rear;
    unsigned quantity;
} Queue;

Queue* initialize();
void destroy(Queue *q);
int is_empty(Queue *q);
unsigned size(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void reverse(Queue *q);
void reverse_recursive(Queue *q);
int peek(Queue *q);
void print(Queue *q);

#endif // QUEUE_H
