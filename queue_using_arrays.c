#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initialize_queue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int is_empty(Queue *queue) {
    return (queue->front == -1);
}

// Check if the queue is full
int is_full(Queue *queue) {
    return (queue->rear == MAX - 1);
}

// Enqueue an element to the queue
void enqueue(Queue *queue, int value) {
    if (is_full(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // First element being enqueued
        }
        queue->arr[++queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return -1 if the queue is empty
    } else {
        int value = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            // Only one element was in the queue, reset the queue
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
        return value;
    }
}

// Peek at the front element of the queue
int peek(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;  // Return -1 if the queue is empty
    }
    return queue->arr[queue->front];
}

// Display the queue elements
void display_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

// Main function for testing
int main() {
    Queue queue;
    initialize_queue(&queue);

    // Enqueue some elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);  // This should indicate that the queue is full

    // Display the queue
    display_queue(&queue);

    // Dequeue some elements
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    // Display the queue
    display_queue(&queue);

    // Peek at the front element
    printf("Front element: %d\n", peek(&queue));

    // Dequeue the rest of the elements
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    // Try to dequeue from an empty queue
    dequeue(&queue);

    return 0;
}
