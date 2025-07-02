#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

Node* deleteNumber(Node* head,int index) {
    if (index == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    int pos = 0;
    while (current != NULL && pos < index-1) {
        prev = current;
        current = current->next;
        pos++;
    }
    if (current == NULL) {
        return 0;
    }
    prev->next = current->next;
    free(current);
    return head;
}

int main(void) {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    int value;
    int index;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i+1);
        scanf("%d", &value);
        Node* newNode = insert(value);
        if (head == NULL) {
            head = tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("nhap index");
    scanf("%d", &index);
    int result = deleteNumber(head, index);
    if (result == 0) {
        printf("nhap lon n");
    }else {
        print(head);
    }
    return 0;
}