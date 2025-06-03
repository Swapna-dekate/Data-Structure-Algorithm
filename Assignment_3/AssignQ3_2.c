#include <stdio.h>
#define SIZE 100

// Stack structure
typedef struct {
    int data[SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

void reverseArray(int arr[], int n) {
    Stack s;
    initStack(&s);


    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }


    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed array:\n");
    printArray(arr, n);

    return 0;
}
