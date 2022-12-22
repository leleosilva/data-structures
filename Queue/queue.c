#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// Creates and returns a queue
Queue* initialize() {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    q->front = q->rear = NULL;
    q->quantity = 0;
    return q;
}

// Destroys a queue. It should be the last function to be used
void destroy(Queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}

// Checks whether a queue is empty or not
int is_empty(Queue *q) {
    return q->quantity == 0;
}

// Returns the size of a queue
unsigned size(Queue *q) {
    return q->quantity;
}

// Enqueues element to the rear of a queue
void enqueue(Queue *q, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->element = data;
    new_node->next = NULL;
    if (q->rear == NULL) { // If rear is NULL, the queue is empty. Therefore, rear and front both are 'new_node'
        q->rear = q->front = new_node;
    }
    /* Queue isn't empty. The rearmost element (now the second to last rearmost) points to the new last node
     * and rear assumes the value of 'new_node' */
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->quantity++;
}

// Dequeues and returns an element from the front of a queue. If the queue is empty, returns -1 by default
int dequeue(Queue *q) {
    int removed_element = -1;

    if (!is_empty(q)) {
        Node *to_be_removed = q->front;
        q->front = to_be_removed->next; // Front will be the node pointed by the removed node

        removed_element = to_be_removed->element;
        free(to_be_removed);

        // If the queue had only one element before its removal, both front and rear should be NULL
        if (q->front == NULL) {
            q->rear = NULL;
        }
        q->quantity--;
    }
    return removed_element;
}

/* Reverses the order of elements in a queue (iterative implementation).
 *
 * Because this queue is internally represented as a singly linked list,
 * reversing functions from both data structures are similar */
void reverse(Queue *q) {
    if (!is_empty(q)) {
        Node *previous_node = q->front;
        q->front = q->front->next;
        Node *current_node = q->front;

        previous_node->next = NULL;

        while (q->front != NULL) {
            q->front = q->front->next;
            current_node->next = previous_node;

            previous_node = current_node;
            current_node = q->front;
        }
        q->front = previous_node;
    }
}

/* Recursive implementation of the reverse() function.
 * It works for queues that aren't internally represented as a singly linked list */
void reverse_recursive(Queue *q) {
    if (q->front == NULL) {
        return;
    }

    /* Removes element from the front and call reverse_recursive() recursively.
     * After all recursive calls are done, enqueue the removed elements again in reverse order */
    int removed_element = dequeue(q);
    reverse_recursive(q);
    enqueue(q, removed_element);
}

// Returns the element at the front of a queue. If the queue is empty, returns -1 by default
int peek(Queue *q) {
    if (!is_empty(q)) {
        return q->front->element;
    }
    else {
        return -1;
    }
}

// Prints a queue
void print(Queue *q) {
    if (!is_empty(q)) {
        Node *current_node = q->front;

        while (current_node != NULL) {
            if (current_node->next != NULL) {
                printf("%d -> ", current_node->element);
            } else {
                printf("%d\n", current_node->element);
            }
            current_node = current_node->next;
        }
    }
}