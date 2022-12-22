#include <stdio.h>

#include "queue.h"

int main() {
    Queue *q = initialize();

    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    printf("ORDER (FROM FRONT TO REAR): ");
    print(q);

    reverse(q);
    printf("\nREVERSE ORDER (FROM FRONT TO REAR): ");
    print(q);

    printf("\nCurrent size: %d\n", size(q));

    printf("\n");
    while (!is_empty(q)) {
        printf("Removed element: %d\n", dequeue(q));
    }
    printf("Removed element: %d\n", dequeue(q));

    printf("\nPeeking element from the front of the queue: %d\n", peek(q));
    printf("\nCurrent size: %d\n", size(q));

    enqueue(q, 14);
    enqueue(q, 40);
    enqueue(q, 26);
    enqueue(q, 37);

    printf("ORDER (FROM FRONT TO REAR): ");
    print(q);

    reverse_recursive(q);
    printf("\nRECURSIVE REVERSE ORDER (FROM FRONT TO REAR): ");
    print(q);

    printf("\nPeeking element from the front of the queue: %d\n", peek(q));
    printf("\nCurrent size: %d\n", size(q));

    destroy(q);
    return 0;
}