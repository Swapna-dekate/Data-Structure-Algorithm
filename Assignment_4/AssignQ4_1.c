#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void insertAfter(Node* head, int target, int data) {
    Node* temp = head;
    while (temp && temp->data != target)
        temp = temp->next;

    if (!temp) {
        printf("Node with value %d not found\n", target);
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


void insertBefore(Node** head, int target, int data) {
    
    if (*head && (*head)->data == target) {
        Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* prev = NULL, *curr = *head;
    while (curr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        printf("Node with value %d not found\n", target);
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = curr;
    prev->next = newNode;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    Node* head = NULL;

    
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Original List:\n");
    printList(head);

    
    insertAfter(head, 20, 25);
    printf("\nAfter inserting 25 after 20:\n");
    printList(head);

    
    insertBefore(&head, 20, 15);
    printf("\nAfter inserting 15 before 20:\n");
    printList(head);
    
    freeList(head);
    return 0;
}