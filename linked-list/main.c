#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node;

node *create_node(int value) {
    node* n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    return n;
}

int isEmpty(node* head) {
    return head == NULL;
}

int size(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void push_front(node** head, node* node_to_insert) {
    node_to_insert->next = (*head);
    (*head) = node_to_insert;
}

void push_back(node** head, node* node_to_insert) {
    node* temp = (*head);
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node_to_insert;
}

int pop_front(node** head) {
    if (isEmpty((*head))) {
        printf("list is empty!\n");
        exit(1);
    }

    int item = (*head)->value;
    node* temp =  (*head);
    (*head) = (*head)->next;
    free(temp);
    return item;
}

void print_list(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void delete(node* head) {
    while (head != NULL) {
        node* next_node =  head->next;
        free(head);
        head = next_node;
    }
}

int main() {
    node* head = NULL;
    push_front(&head, create_node(3));
    push_front(&head, create_node(2));
    push_front(&head, create_node(1));
    push_back(&head, create_node(4));
    print_list(head);
    printf("%d\n", size(head));
    pop_front(&head);
    print_list(head);
    printf("%d\n", size(head));

    delete(head);
    return 0;
}