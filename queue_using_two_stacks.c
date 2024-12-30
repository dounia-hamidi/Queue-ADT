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
    stack s1, s2;
};

typedef struct Queue queue;

void initializeQueue(queue *q) {
    initializeStack(&q->s1);
    initializeStack(&q->s2);
}

void enqueue(queue *q, int value) {
    push(&q->s1, value);
}

int dequeue(queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

void displayQueue(queue *q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = 0; i <= q->s1.top; i++) {
            printf("%d ", q->s1.items[i]);
        }
        for (int i = q->s2.top; i >= 0; i--) {
            printf("%d ", q->s2.items[i]);
        }
        printf("\n");
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

    printf("Dequeued: %d\n", dequeue(&q));
    displayQueue(&q);

    enqueue(&q, 6);
    displayQueue(&q);

    return 0;
}
