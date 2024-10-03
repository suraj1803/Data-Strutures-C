#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* parent;
    struct node* left;
    struct node* right;
}node;

node* create_node(int value) {
    node* n = malloc(sizeof(node));
    n->value = value;
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void print(node* root) {
    if (root == NULL) {
        return;
    }

    print(root->left);
    printf("%d ", root->value);
    print(root->right);
}

void delete(node* root) {
    if (root == NULL) 
        return;
    
    node* left = root->left;
    node* right = root->right;

    free(root);

    delete(left);
    delete(right);
}

int main() {
    node* root = create_node(1);
    root->left = create_node(2);
    root->left->parent = root;
    root->right = create_node(3);
    root->right->parent = root;
    print(root);
    delete(root);

    return 0;
}
