#include <stdio.h>

#include "deque.h"

int main() {
    Deque *d = initialize();

    push_rear(d, 1);
    push_front(d, 2);
    push_rear(d, 3);
    push_front(d, 4);
    push_rear(d, 5);

    printf("\nORDER FROM FRONT TO REAR: "); print(d, true);
    printf("\nORDER FROM REAR TO FRONT: "); print(d, false);

    printf("\nCurrent size: %d\n", size(d));
    printf("Front value: %d\n", get_front(d));
    printf("Rear value: %d\n\n", get_rear(d));

    while (!is_empty(d)) {
        printf("Removed element: %d\n", pop_rear(d));
    }
    printf("Removed element: %d\n", pop_front(d));

    push_front(d, 12);
    push_rear(d, -4);
    push_front(d, 55);
    push_rear(d, 27);
    push_front(d, 0);
    push_front(d, 93);

    printf("\nORDER FROM FRONT TO REAR: "); print(d, true);
    printf("\nORDER FROM REAR TO FRONT: "); print(d, false);

    printf("\nCurrent size: %d\n", size(d));
    clear(d);
    printf("\nSize after clearing deque: %d\n", size(d));

    push_front(d, 127);
    printf("\nSize after 1 push operation: %d\n", size(d));

    printf("\nORDER FROM FRONT TO REAR: "); print(d, true);

    printf("\nElement removed: %d\n", pop_front(d));

    destroy(d);
}