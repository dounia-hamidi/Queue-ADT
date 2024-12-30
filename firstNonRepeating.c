#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256  // Assuming ASCII characters

// Queue structure to maintain the order of characters
typedef struct Queue {
    char arr[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initialize_queue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int is_empty_queue(Queue *queue) {
    return (queue->front == -1);
}

// Function to enqueue a character
void enqueue(Queue *queue, char c) {
    if (queue->rear == MAX - 1) {
        printf("Queue overflow!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // First element being enqueued
        }
        queue->arr[++queue->rear] = c;
    }
}

// Function to dequeue a character
char dequeue(Queue *queue) {
    if (is_empty_queue(queue)) {
        return -1;  // Return -1 if the queue is empty
    } else {
        char value = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            // Only one element was in the queue, reset the queue
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
        return value;
    }
}

// Function to print the first non-repeating character
void print_first_non_repeating(char *stream) {
    Queue queue;
    int frequency[MAX] = {0};  // Frequency array to store the count of characters
    initialize_queue(&queue);

    // Iterate through the stream of characters
    for (int i = 0; stream[i] != '\0'; i++) {
        char current_char = stream[i];

        // Enqueue the current character and update its frequency
        enqueue(&queue, current_char);
        frequency[current_char]++;

        // Check the front of the queue and dequeue if needed
        while (!is_empty_queue(&queue) && frequency[queue.arr[queue.front]] > 1) {
            dequeue(&queue);  // Remove repeating characters from the front
        }

        // Print the first non-repeating character if the queue is not empty
        if (!is_empty_queue(&queue)) {
            printf("First non-repeating character after '%c': %c\n", current_char, queue.arr[queue.front]);
        } else {
            printf("First non-repeating character after '%c': None\n", current_char);
        }
    }
}

int main() {
    char stream[MAX];

    // Take input as a continuous stream of characters
    printf("Enter the stream of characters: ");
    fgets(stream, sizeof(stream), stdin);  // Use fgets to read input with spaces (if any)

    // Remove the newline character if present
    stream[strcspn(stream, "\n")] = '\0';

    // Call the function to print the first non-repeating character after each insertion
    print_first_non_repeating(stream);

    return 0;
}

