#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

// Creates and returns a deque
Deque* initialize() {
    Deque *d = malloc(sizeof(Deque));
    if (d == NULL) {
        return NULL;
    }
    d->rear = d->front = NULL;
    d->quantity = 0;
    return d;
}

// Destroys a deque. It should be the last function to be used
void destroy(Deque *d) {
    while (!is_empty(d)) {
        pop_front(d);
    }
    free(d);
}

// Checks whether a deque is empty or not
int is_empty(Deque *d) {
    return d->quantity == 0;
}

// Returns the size of a deque
unsigned size(Deque *d) {
    return d->quantity;
}

// Pushes element to the front of a deque
void push_front(Deque *d, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->element = data;
    new_node->previous = NULL;

    if (d->front == NULL) { // If front is NULL, the deque is empty
        d->front = d->rear = new_node; // Both front and rear are the new node
        new_node->next = NULL; // 'next' and 'previous' pointers of 'new_node' point to NULL
    }
    /* Deque isn't empty. The first node (now the second one) points to the new first node
     * and front assumes the value of 'new_node' */
    else {
        new_node->next = d->front; // 'next' pointer of 'new_node' points to the second node
        d->front->previous = new_node;
        d->front = new_node;
    }
    d->quantity++;
}

// Pushes element to the rear of a deque
void push_rear(Deque *d, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->element = data;
    new_node->next = NULL;

    if (d->rear == NULL) { // If rear is NULL, the deque is empty
        d->rear = d->front = new_node; // Both front and rear are the new node
        new_node->previous = NULL; // 'previous' and 'next' pointers of 'new_node' point to NULL
    }
    /* Deque isn't empty. The rearmost node (now the second to last rearmost) points to the new last node
     * and rear assumes the value of 'new_node' */
    else {
        new_node->previous = d->rear; // 'previous' pointer of 'new_node' points to the second to last node
        d->rear->next = new_node;
        d->rear = new_node;
    }
    d->quantity++;
}

// Pops and returns an element from the front of a deque. If the deque is empty, returns -1 by default
int pop_front(Deque *d) {
    int removed_element = -1;

    if (!is_empty(d)) {
        Node *to_be_removed = d->front;
        removed_element = to_be_removed->element;

        d->front = to_be_removed->next; // Front will be the node pointed by the 'next' pointer of the removed node

        // If the deque had only one element before its removal, both front and rear should be NULL
        if (d->front == NULL) {
            d->rear = NULL;
        } else {
            d->front->previous = NULL; // Front element removed; 'previous' node of the new front points to NULL
        }
        free(to_be_removed);
        d->quantity--;
    }
    return removed_element;
}

// Pops and returns an element from the rear of a deque. If the deque is empty, returns -1 by default
int pop_rear(Deque *d) {
    int removed_element = -1;

    if (!is_empty(d)) {
        Node *to_be_removed = d->rear;
        removed_element = to_be_removed->element;

        d->rear = to_be_removed->previous; // Rear will be the node pointed by the 'previous' pointer of the removed node

        // If the deque had only one element before its removal, both front and rear should be NULL
        if (d->rear == NULL) {
            d->front = NULL;
        } else {
            d->rear->next = NULL; // Rear element removed; 'next' node of the new rear points to NULL
        }
        free(to_be_removed);
        d->quantity--;
    }
    return removed_element;
}

// Returns the element at the front of a deque. If the deque is empty, returns -1 by default
int get_front(Deque *d) {
    if (!is_empty(d)) {
        return d->front->element;
    } else {
        return -1;
    }
}

// Returns the element at the rear of a deque. If the deque is empty, returns -1 by default
int get_rear(Deque *d) {
    if (!is_empty(d)) {
        return d->rear->element;
    } else {
        return -1;
    }
}

// Clears a deque, removing all its elements
void clear(Deque *d) {
    while (!is_empty(d)) {
        pop_front(d);
    }
}

/* Prints a deque
 * If 'front_to_rear' is true, prints from front to rear; Otherwise, prints from rear to front. */
void print(Deque *d, bool front_to_rear) {
    if (!is_empty(d)) {
        if (front_to_rear) {
            print_front_to_rear(d);
        } else {
            print_rear_to_front(d);
        }
    }
}

// Auxiliary function that prints a deque from front to rear
void print_front_to_rear(Deque *d) {
    Node *current_node = d->front;

    while (current_node != NULL) {
        if (current_node->next != NULL) {
            printf("%d -> ", current_node->element);
        } else {
            printf("%d\n", current_node->element);
        }
        current_node = current_node->next;
    }
}

// Auxiliary function that prints a deque from rear to front
void print_rear_to_front(Deque *d) {
    Node *current_node = d->rear;

    while (current_node != NULL) {
        if (current_node->previous != NULL) {
            printf("%d -> ", current_node->element);
        } else {
            printf("%d\n", current_node->element);
        }
        current_node = current_node->previous;
    }
}