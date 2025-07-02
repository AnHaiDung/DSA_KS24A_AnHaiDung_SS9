#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* insert(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    int index = 1;
    while (head != NULL) {
        printf("Node %d: %d\n ",index ,head->data);
        head = head->next;
        index++;
    }
}

int main(void) {
    Node* head = NULL;
    int n;
    int value;
    int num;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap so muon them");
    scanf("%d", &num);
    head = insert(head, num);
    printList(head);
    return 0;
}