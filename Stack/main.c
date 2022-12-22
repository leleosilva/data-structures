#include <stdio.h>

#include "stack.h"

int main() {
    Stack *s = initialize();

    printf("Current size: %d\n\n", size(s));

    push(s, 3);
    push(s, 1);
    push(s, 2);
    push(s, 7);
    push(s, 4);
    push(s, 5);
    push(s, 4);

    printf("ORIGINAL ORDER\n");
    print(s);
    printf("\nREVERSED ORDER\n");
    reverse(s);
    print(s);
    printf("\nCurrent size: %d\n\n", size(s));

    while (!is_empty(s)) {
        printf("Element removed: %d\n", pop(s));
    }
    printf("\n");

    push(s, 13);
    push(s, 17);
    push(s, 11);
    push(s, 19);

    reverse(s);
    reverse(s);

    print(s);
    printf("\nCurrent size: %d\n\n", size(s));

    while (!is_empty(s)) {
        printf("Top of the stack: %d\n", top(s));
        pop(s);
    }
    printf("Top of the stack: %d\n", top(s));

    destroy(s);
    return 0;
}