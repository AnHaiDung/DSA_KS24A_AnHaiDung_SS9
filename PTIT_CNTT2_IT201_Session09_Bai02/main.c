#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void print(Node* head) {
    int index = 1;
    while (head != NULL) {
        printf("phan tu thu %d: %d ",index, head->data);
        head = head->next;
        index++;
    }
}

int main(void) {
    Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    print(head);
    return 0;
}