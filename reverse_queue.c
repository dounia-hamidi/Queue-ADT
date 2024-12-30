#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Stack {
    int items[SIZE];
    int top;
};

typedef struct Stack stack;

void initializeStack(stack *s) {
    s->top = -1;
}

int isFull(stack *s) {
    return s->top == SIZE - 1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

struct Queue {
    int items[SIZE];
    int front, rear;
};

typedef struct Queue queue;

void initializeQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(queue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

int isQueueEmpty(queue *q) {
    return q->front == -1;
}

void enqueue(queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
    }
}

int dequeue(queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        return element;
    }
}

void reverseQueue(queue *q) {
    stack s1, s2;
    initializeStack(&s1);
    initializeStack(&s2);

    while (!isQueueEmpty(q)) {
        push(&s1, dequeue(q));
    }

    while (!isEmpty(&s1)) {
        push(&s2, pop(&s1));
    }

    while (!isEmpty(&s2)) {
        enqueue(q, pop(&s2));
    }
}

void displayQueue(queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        int i = q->front;
        printf("Queue: ");
        while (i != q->rear) {
            printf("%d ", q->items[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", q->items[i]);
    }
}

int main() {
    queue q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    displayQueue(&q);

    reverseQueue(&q);
    displayQueue(&q);

    return 0;
}

