#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// Creates and returns a stack
Stack* initialize() {
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    s->top = NULL;
    s->quantity = 0;
    return s;
}

// Destroys a stack. It should be the last function to be used
void destroy(Stack *s) {
    while (!is_empty(s)) {
        pop(s);
    }
    free(s);
}

// Checks whether a stack is empty
int is_empty(Stack *s) {
    return s->quantity == 0;
}

// Returns the size of a stack
unsigned size(Stack *s) {
    return s->quantity;
}

// Pushes element to the top of a stack
void push(Stack *s, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->item = data;

    // 'new_node' will be placed above the node that was at the top before (s->top) and will point to it
    new_node->next = s->top;

    s->top = new_node; // Top pointer now changes to point to 'new_node'
    s->quantity++;
}

// Pops and returns element from the top of a stack. If the stack is empty, returns -1 by default
int pop(Stack *s) {
    int removed_element = -1;

    if (!is_empty(s)) {
        Node *to_be_removed = s->top;
        removed_element = to_be_removed->item;
        s->top = to_be_removed->next; // Top pointer now points to the next element on top of the stack

        free(to_be_removed);
        s->quantity--;
    }
    return removed_element;
}

// Returns the element on top of a stack. If the stack is empty, returns -1 by default
int top(Stack *s) {
    if (!is_empty(s)) {
        return s->top->item;
    }
    else {
        return -1;
    }
}

// Prints a stack
void print(Stack *s) {
    Node *current_node = s->top;

    while (current_node != NULL) { // Prints the stack from top to bottom
        printf("%d\n", current_node->item);
        current_node = current_node->next;
    }
}