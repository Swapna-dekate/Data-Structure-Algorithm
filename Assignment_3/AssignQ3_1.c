#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int top;
} DescendingStack;

// Initialize the stack
void initialize(DescendingStack *stack) {
    stack->top = SIZE;
}

// Check if the stack is empty
bool isEmpty(DescendingStack *stack) {
    return stack->top == SIZE;
}

// Check if the stack is full
bool isFull(DescendingStack *stack) {
    return stack->top == 0;
}

// Push an element onto the stack
void push(DescendingStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top--;
    stack->arr[stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Pop an element from the stack
int pop(DescendingStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top++;
    printf("Popped %d from the stack\n", popped);
    return popped;
}

// Peek at the top element of the stack
int peek(DescendingStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    DescendingStack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack); 

    return 0;
}