// LeetCode 226 - Invert Binary Tree
// Given the root of a binary tree, invert the tree (mirror it), and return its root.
// Approach: Recursive DFS — swap left and right children at every node, O(n) time.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
    if (!root) return NULL;

    struct TreeNode *tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);

    return root;
}

// Helper to create a node
struct TreeNode *newNode(int val) {
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

// Level-order print for verification
void printLevelOrder(struct TreeNode *root) {
    if (!root) { printf("[]\n"); return; }

    struct TreeNode *queue[1024];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("[");
    int first = 1;
    while (front < rear) {
        struct TreeNode *node = queue[front++];
        if (!first) printf(", ");
        printf("%d", node->val);
        first = 0;
        if (node->left)  queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
    printf("]\n");
}

void freeTree(struct TreeNode *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    // Tree: 4 -> left:2(left:1,right:3), right:7(left:6,right:9)
    struct TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    printf("Before: "); printLevelOrder(root);
    // Expected before: [4, 2, 7, 1, 3, 6, 9]

    root = invertTree(root);

    printf("After:  "); printLevelOrder(root);
    // Expected after:  [4, 7, 2, 9, 6, 3, 1]

    freeTree(root);
    return 0;
}
