#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int height;
    struct node *left;
    struct node *right;
} Node;

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

int balance_factor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *right_rotate(Node *node) {
    Node *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
}

Node *left_rotate(Node *node) {
    Node *new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
}

Node *insert(Node *node, int value) {
    if (node == NULL) {
        node = (Node *)malloc(sizeof(Node));
        node->value = value;
        node->height = 0;
        node->left = NULL;
        node->right = NULL;
    } else if (value < node->value) {
        node->left = insert(node->left, value);
        if (balance_factor(node) == 2) {
            if (balance_factor(node->left) == 1) {
                node = right_rotate(node);
            } else {
                node->left = left_rotate(node->left);
                node = right_rotate(node);
            }
        }
    } else if (value > node->value) {
        node->right = insert(node->right, value);
        if (balance_factor(node) == -2) {
            if (balance_factor(node->right) == -1) {
                node = left_rotate(node);
            } else {
                node->right = right_rotate(node->right);
                node = left_rotate(node);
            }
        }
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    return node;
}

void print_inorder(Node *node) {
    if (node != NULL) {
        print_inorder(node->left);
        printf("%d ", node->value);
        print_inorder(node->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    printf("Inorder traversal of the AVL tree: ");
    print_inorder(root);
    printf("\n");
    return 0;
}