#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

typedef struct CircularQueue cq;

void initialize(cq *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(cq *q) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->front == q->rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty(cq *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(cq *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(cq *q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        return element;
    }
}

void display(cq *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front -> %d ", q->front);
        printf("Items -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d ", q->items[i]);
        printf("Rear -> %d\n", q->rear);
    }
}

int main() {
    cq q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 6);
    display(&q);

    return 0;
}

