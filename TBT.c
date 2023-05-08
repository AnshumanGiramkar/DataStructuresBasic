#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    bool leftThread;
    bool rightThread;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = true;
    newNode->rightThread = true;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data) {
        struct Node* leftChild = root->left;
        if (root->leftThread) {
            struct Node* newNode = createNode(data);
            newNode->left = leftChild;
            newNode->right = root;
            root->left = newNode;
            root->leftThread = false;
        } else {
            insert(leftChild, data);
        }
    } else {
        struct Node* rightChild = root->right;
        if (root->rightThread) {
            struct Node* newNode = createNode(data);
            newNode->left = root;
            newNode->right = rightChild;
            root->right = newNode;
            root->rightThread = false;
        } else {
            insert(rightChild, data);
        }
    }
    return root;
}

struct Node* leftmostNode(struct Node* node) {
    while (node != NULL && node->left != NULL && !node->leftThread)
        node = node->left;
    return node;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* node = leftmostNode(root);
    while (node != NULL) {
        printf("%d ", node->data);
        if (node->rightThread)
            node = node->right;
        else
            node = leftmostNode(node->right);
    }
    printf("\n");
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    if (!root->leftThread)
        preorderTraversal(root->left);
    if (!root->rightThread)
        preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    if (!root->leftThread)
        postorderTraversal(root->left);
    if (!root->rightThread)
        postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
