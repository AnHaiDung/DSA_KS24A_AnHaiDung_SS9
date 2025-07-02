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

Node* delete(Node* head, int num) {
    Node* current = head;
    Node* pre = NULL;
    if (head->data == num) {
        head = head->next;
        free(current);
        return head;
    }
    while (current != NULL) {
        if (current->data == num) {
            pre->next =current->next;
            free(current);
            return head;
        }
        pre = current;
        current = current -> next;
    }
    return 0;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current -> next;
    }
}

int main(void) {
    int n;
    int value;
    int num;
    Node *head = NULL;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan thu %d: ",i+1);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap phan tu muon xoa");
    scanf("%d", &num);
    int res = delete(head, num);
    if (res == 0) {
        printf("khong tim thay");
    } else {
        printList(head);
    }
    return 0;
}