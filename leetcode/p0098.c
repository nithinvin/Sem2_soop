// LeetCode 98 - Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid BST.
// A valid BST: left subtree values < node < right subtree values.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool validate(struct TreeNode *node, long minVal, long maxVal) {
    if (!node) return true;
    if ((long)node->val <= minVal || (long)node->val >= maxVal) return false;
    return validate(node->left, minVal, (long)node->val) &&
           validate(node->right, (long)node->val, maxVal);
}

bool isValidBST(struct TreeNode *root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

// Helper to create a tree node
struct TreeNode *newNode(int val) {
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

int main(void) {
    // Tree: 2 -> left:1, right:3
    struct TreeNode *root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);
    printf("Tree1 valid BST: %s\n", isValidBST(root1) ? "true" : "false"); // true

    // Tree: 5 -> left:1, right:4 -> left:3, right:6
    struct TreeNode *root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);
    printf("Tree2 valid BST: %s\n", isValidBST(root2) ? "true" : "false"); // false

    // Free trees
    free(root1->left); free(root1->right); free(root1);
    free(root2->right->left); free(root2->right->right);
    free(root2->right); free(root2->left); free(root2);

    return 0;
}
