#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Define the maximum size of the queue

// Circular Queue Structure
struct CircularQueue {
    int array[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int is_full(struct CircularQueue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to check if the queue is empty
int is_empty(struct CircularQueue *q) {
    return q->front == -1;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    if (q->front == -1) {
        q->front = 0;  // First element being added
    }

    q->rear = (q->rear + 1) % MAX_SIZE;  // Circular increment
    q->array[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Return a sentinel value indicating an empty queue
    }

    int value = q->array[q->front];

    // If only one element is left, reset the queue
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;  // Circular increment
    }

    return value;
}

// Function to peek at the front element of the queue
int peek(struct CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;
    }

    return q->array[q->front];
}

// Function to display the elements of the queue
void display(struct CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    while (i != q->rear) {
        printf("%d <- ", q->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->array[q->rear]);
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    // Testing the Circular Queue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Trying to enqueue when the queue is full
    enqueue(&queue, 60);

    // Display the queue
    display(&queue);

    // Dequeue some elements
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    // Display the queue after dequeuing
    display(&queue);

    // Peek at the front element
    printf("Front element: %d\n", peek(&queue));

    return 0;
}
