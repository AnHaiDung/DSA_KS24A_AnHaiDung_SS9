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
    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->next;
    }
}

Node* addNumber(Node* head, int index, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (index == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    int pos = 0;
    while (current !=NULL && pos < index-1) {
        current = current->next;
        pos++;
    }
    if (current == NULL) {
        return 0;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main(void) {
    int n;
    int value;
    int num;
    int index;
    Node* head = NULL;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("phan tu %d: ", i);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap so muon them");
    scanf("%d", &num);
    printf("nhap index");
    scanf("%d", &index);
    int result = addNumber(head, index, num);
    if (result == 0) {
        printf("khong hop le");
    }else {
        print(head);
    }
    return 0;
}