#include <stdio.h>
#include "queue.h"

int main()
{
    Queue* queue = CreateQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);

    printf("\nPeeking: %d %s\n", peekQueue(queue), "\n");

    freeQueue(queue);
    return 0;
}