#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct singlylinkedlist {
    Node *head;
} SinglyLinkedList;

SinglyLinkedList* initialize();
void destroy(SinglyLinkedList *l);
int is_empty(SinglyLinkedList *l);
unsigned size(SinglyLinkedList *l);
void prepend(SinglyLinkedList *l, int data);
void append(SinglyLinkedList *l, int data);
int insert_by_index(SinglyLinkedList *l, int data, int idx);
int pop_first(SinglyLinkedList *l);
int pop_last(SinglyLinkedList *l);
int remove_by_index(SinglyLinkedList *l, int idx);
void reverse(SinglyLinkedList *l);
void print(SinglyLinkedList *l);

#endif // SINGLYLINKEDLIST_H
