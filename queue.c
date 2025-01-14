#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue* CreateQueue()
{
    Queue* queue = (Queue*)calloc(1, sizeof(Queue));
    return queue;
}

bool isQueueEmpty(const Queue* queue)
{
    return queue->size == 0;
}

static QueueNode* CreateQueueNode(const int data)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(Queue* queue, int data)
{
    QueueNode* node = CreateQueueNode(data);

    if(!isQueueEmpty(queue))
    {
        // Add the new node to the end of the q
        queue->rear->next = node;
        // Set the new rear pointer 
        queue->rear = node;
    }

    else
    {
        queue->front = node;
        queue->rear = node;
    }
    queue->size++;
}

int dequeue(Queue* queue)
{
    if (!isQueueEmpty(queue))
    {
        int retVal = queue->front->data;
        QueueNode* newFront = queue->front->next;
        free(queue->front);

        queue->front = newFront;

        // If we dequeue at size 1, q becomes empty, update rear pointer
        if(queue->size == 1)
            queue->rear = NULL;

        queue->size--;
        return retVal;
    }

    return -1;
}

int peekQueue(Queue* queue)
{
    if (!isQueueEmpty(queue))
        return queue->front->data;
    
    return -1;
}

void freeQueue(Queue* queue)
{
    if(queue == NULL)
        return;

    QueueNode* curr = queue->front;

    while(curr)
    {
        QueueNode* next = curr->next;
        free(curr);
        curr = next;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    free(queue);
}

void printQueue(const Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue [Size %d]: ", queue->size);
    QueueNode* current = queue->front;

    while (current)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> "); 
        }
        current = current->next;
    }

    printf("\n");
}