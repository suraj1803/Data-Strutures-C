#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* node = malloc(sizeof(Node));
    node -> val = val;
    node -> next = NULL;
    return node;
}

void insertAtFront(Node** head, int val) {
    Node* node = createNode(val);
    node -> next = *head;
    *head = node;
}

void insertAtBack(Node** head, int val) {
    Node* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
}

void insert(Node** head, int val, int idx) {
    /*
     * if list is empty and idx == 0 then insert node in first pos
     * otherwise just return
    */
    if (*head == NULL) {
        if (idx == 0) {
            Node* node = createNode(val);
            *head = node;
        }
        return;
    }

    /*
     * reach the index before idx and insert the node;
    */
    int cnt = 0;
    Node* node = *head;
    while (cnt != idx - 1) {
        if (node == NULL) {
            return;
        }
        node = node->next;
        cnt++;
    }

    Node* temp = createNode(val);
    temp -> next = node->next;
    node -> next = temp;
}

void printList(Node** head) {
    Node *node = *head;
    while (node != NULL) {
        printf("%d ", node -> val);
        node = node -> next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 1, 0);
    insert(&head, 2, 1);
    printList(&head);
    
    return 0;
}
