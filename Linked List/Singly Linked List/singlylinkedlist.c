#include <stdio.h>
#include <stdlib.h>

#include "singlylinkedlist.h"

// Creates and returns a singly linked list
SinglyLinkedList* initialize() {
    SinglyLinkedList *l = malloc(sizeof(SinglyLinkedList));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    return l;
}

// Destroys a singly linked list. It should be the last function to use
void destroy(SinglyLinkedList *l) {
    if (!is_empty(l)) {
        Node *current_node = l->head;
        l->head = l->head->next;
        free(current_node);
    }
    free(l);
}

// Returns if a singly linked list is empty (true = 1, false = 0)
int is_empty(SinglyLinkedList *l) {
    return l->head == NULL;
}

// Returns the size of a singly linked list
unsigned size(SinglyLinkedList *l) {
    unsigned count = 0;

    Node *current_node = l->head;
    while (current_node != NULL) {
        current_node = current_node->next;
        count++;
    }
    return count;
}

// Add node to the beginning of a singly linked list
void prepend(SinglyLinkedList *l, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = data;
    new_node->next = l->head;
    l->head = new_node; // Head now points to 'new_node'
}

// Add node to the end of a singly linked list
void append(SinglyLinkedList *l, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = data;
    new_node->next = NULL;

    if (l->head == NULL) { // Linked list is empty, head points to 'new_node'
        l->head = new_node;
    }
    else{ // Linked list isn't empty, traverse until the last node
        Node *current_node = l->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node; // Last node now is the second to last node and points to 'new_node'
    }
}

/* Add node to a singly linked list at the specified index from 0 to size() and return whether the element could be
 * inserted successfully. */
int insert_by_index(SinglyLinkedList *l, int data, int idx) {
    if (idx < 0 || idx > size(l)) { // Checking if index is valid
        printf("Invalid index. Element not inserted.\n");
        return 0;
    }

    if (idx == 0) { // First position; prepend the element
        prepend(l, data);
    }
    else if (idx == size(l)) { // Last position; append the element
        append(l, data);
    }
    else { // Any other position
        Node *current_node = l->head;
        for (int current_idx = 0; current_idx < idx - 1; current_idx++) { // Traverse linked list till (idx - 1)
            current_node = current_node->next;
        }
        Node *new_node = malloc(sizeof(Node));
        new_node->value = data;
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    return 1;
}

// Remove and return the first node from a singly linked list. Returns -1 by default
int pop_first(SinglyLinkedList *l) {
    int removed_value = -1;

    if (!is_empty(l)) {
        removed_value = l->head->value;

        Node *first_node = l->head;
        l->head = l->head->next; // Moves head pointer to next node

        free(first_node);
        first_node = NULL;
    }
    return removed_value;
}

// Remove and return the last node from a singly linked list. Returns -1 by default
int pop_last(SinglyLinkedList *l) {
    int removed_value = -1;

    if (!is_empty(l)) {
        if (l->head->next == NULL) { // Linked list has only one element which will be removed
            removed_value = l->head->value;
            free(l->head);
            l->head = NULL;
        }
        else {
            Node *current_node = l->head;
            while (current_node->next->next != NULL) {
                current_node = current_node->next;
            }
            removed_value = current_node->next->value;
            free(current_node->next);
            current_node->next = NULL;
        }
    }
    return removed_value;
}

/* Remove node to a singly linked list at the specified index from 0 to size() and return the element removed.
 * If the index is invalid, return -1 by default. */
int remove_by_index(SinglyLinkedList *l, int idx) {
    if (idx < 0 || idx > size(l)) { // Checking if index is valid
        printf("Invalid index. Element not inserted.\n");
        return -1;
    }

    if (idx == 0) { // First position; pop the first element
        return pop_first(l);
    }
    else if (idx == size(l)) { // Last position; pop the last element
        return pop_last(l);
    }
    else { // Any other position
        Node *current_node = l->head; // After traversing, 'current_node' will be the node before the node to be removed
        for (int current_idx = 0; current_idx < idx - 1; current_idx++) { // Traverse linked list till (idx - 1)
            current_node = current_node->next;
        }
        /* Sketch: current_node -> to_be_removed -> next_node.
         * 'to_be_removed' will be removed and current_node will point to next_node */
        Node *to_be_removed = current_node->next;
        current_node->next = to_be_removed->next;
        int removed_element = to_be_removed->value;

        free(to_be_removed);
        to_be_removed = NULL;

        return removed_element;
    }
}

// Reverses the order of nodes of a singly linked list
void reverse(SinglyLinkedList *l) {
    if (!is_empty(l)) {
        Node *previous_node = l->head;
        l->head = l->head->next;
        Node *current_node = l->head;

        previous_node->next = NULL;

        while (l->head != NULL) {
            l->head = l->head->next;
            current_node->next = previous_node;

            previous_node = current_node;
            current_node = l->head;
        }
        l->head = previous_node;
    }
}

// Prints a singly linked list (element_0 -> element_1 -> ... -> element_n)
void print(SinglyLinkedList *l) {
    Node *current_node = l->head;

    while (current_node != NULL) {
        if (current_node->next != NULL) {
            printf("%d -> ", current_node->value);
        }
        else {
            printf("%d\n", current_node->value);
        }
        current_node = current_node->next;
    }
}