#include <stdio.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return q->count == MAX;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

// Function to add an element to the queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow. Cannot enqueue %d\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    q->count++;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow. Cannot dequeue.\n");
        return;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Dequeued: %d\n", value);
}

// Function to display the elements of the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->items[index]);
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Queue is now full
    enqueue(&q, 60); // Should display overflow message

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70); // Should display overflow message if queue is full

    display(&q);

    return 0;
}
