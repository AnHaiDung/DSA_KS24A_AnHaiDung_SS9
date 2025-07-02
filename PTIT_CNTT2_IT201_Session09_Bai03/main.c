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

int findNumber(Node* head,int num) {
    while (head != NULL) {
        if (head->data == num) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}


int main(void) {
    Node* head = NULL;
    int n;
    int value;
    int num;
    printf("nhap n phan tu: ");
    scanf("%d", &n);
    if (n<0) {
        printf("khong hop le");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap so can tim");
    scanf("%d", &num);
    int res = findNumber(head, num);
    if (res == 1) {
        printf("True");
    }else{
        printf("False");
    }

    return 0;
}