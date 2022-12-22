#ifndef STACK_H
#define STACK_H

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    unsigned quantity;
} Stack;

Stack* initialize();
void destroy(Stack *s);
int is_empty(Stack *s);
unsigned size(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);
void reverse(Stack *s);
int top(Stack *s);
void print(Stack *s);

#endif // STACK_H
