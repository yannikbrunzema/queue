#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for the queue
typedef struct Queue
{
    QueueNode* front; // Points to the front of the queue
    QueueNode* rear;  // Points to the rear of the queue
    int size;         // Number of elements in the queue
} Queue;


/**
 * @brief Creates and initializes a new queue.
 * 
 * @return Pointer to the newly created queue.
 */
Queue* CreateQueue();

/**
 * @brief Checks if the queue is empty.
 * 
 * @param queue Pointer to the queue.
 * @return True if the queue is empty, false otherwise.
 */
bool isQueueEmpty(const Queue* queue);

/**
 * @brief Adds an element to the rear of the queue.
 * 
 * @param queue Pointer to the queue.
 * @param data The data to enqueue.
 */
void enqueue(Queue* queue, int data);

/**
 * @brief Removes and returns the front element of the queue.
 * 
 * @param queue Pointer to the queue.
 * @return The data at the front of the queue. Returns -1 if the queue is empty.
 */
int dequeue(Queue* queue);

/**
 * @brief Returns the front element of the queue without removing it.
 * 
 * @param queue Pointer to the queue.
 * @return The data at the front of the queue. Returns -1 if the queue is empty.
 */
int peekQueue(Queue* queue);

/**
 * @brief Frees the memory allocated for the queue.
 * 
 * @param queue Pointer to the queue to free.
 */
void freeQueue(Queue* queue);

/**
 * @brief Prints a queue
 * 
 * @param queue const pointer to the queue to print
 */
void printQueue(const Queue* queue);


#endif // QUEUE_H