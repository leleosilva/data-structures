#include <stdio.h>
#include <stdlib.h>

#include "singlylinkedlist.h"

int main() {
    SinglyLinkedList *l = initialize();

    append(l, 2);
    prepend(l, 5);
    prepend(l, 3);
    prepend(l, 1);
    append(l, 6);
    prepend(l, 4);
    append(l, 8);


    printf("Is the list empty? %d\n", is_empty(l));
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value1 = pop_last(l);
    printf("Removed value: %d\n", value1);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value2 = pop_first(l);
    printf("Removed value: %d\n", value2);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value3 = pop_last(l);
    printf("Removed value: %d\n", value3);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value4 = pop_last(l);
    printf("Removed value: %d\n", value4);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value5 = pop_last(l);
    printf("Removed value: %d\n", value5);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value6 = pop_first(l);
    printf("Removed value: %d\n", value6);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value7 = pop_first(l);
    printf("Removed value: %d\n", value7);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    int value8 = pop_first(l);
    printf("Removed value: %d\n", value8);
    printf("size: %d\n", size(l));
    print(l);
    printf("\n");

    printf("Is the list empty? %d\n", is_empty(l));
    printf("\n");

    printf("Element inserted? %d\n", insert_by_index(l, 34, 0));
    printf("Element inserted? %d\n", insert_by_index(l, 35, 1));
    printf("Element inserted? %d\n", insert_by_index(l, 36, 2));
    printf("Element inserted? %d\n", insert_by_index(l, 37, 2));
    printf("Element inserted? %d\n", insert_by_index(l, 38, 1));
    printf("Element inserted? %d\n", insert_by_index(l, 40, 4));

    printf("\n");
    print(l);
    printf("Is the list empty? %d\n", is_empty(l));

    reverse(l);
    print(l);
    printf("\n");

    printf("Element removed: %d\n", remove_by_index(l, 2));
    printf("Element removed: %d\n", remove_by_index(l, 5));
    printf("Element removed: %d\n", remove_by_index(l, 7));
    printf("Element removed: %d\n", remove_by_index(l, 1));
    printf("Element removed: %d\n", remove_by_index(l, 1));
    printf("Element removed: %d\n", remove_by_index(l, 1));
    printf("Element removed: %d\n", remove_by_index(l, 0));
    printf("Element removed: %d\n", remove_by_index(l, 0));

    printf("\n");
    print(l);
    printf("Is the list empty? %d\n", is_empty(l));

    destroy(l);
    return 0;
}