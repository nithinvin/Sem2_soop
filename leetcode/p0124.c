// LeetCode 124 - Binary Tree Maximum Path Sum (Hard)
// A path in a binary tree is a sequence of nodes where each pair of adjacent
// nodes has an edge. The path sum is the sum of the node values in the path.
// Return the maximum path sum of any non-empty path.
// Approach: DFS post-order traversal, O(n) time.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int globalMax;

int maxGain(struct TreeNode *node) {
    if (!node) return 0;

    // Max gain from left and right subtrees (ignore negative contributions)
    int leftGain = maxGain(node->left);
    if (leftGain < 0) leftGain = 0;

    int rightGain = maxGain(node->right);
    if (rightGain < 0) rightGain = 0;

    // Path through this node as the highest point
    int pathSum = node->val + leftGain + rightGain;
    if (pathSum > globalMax) globalMax = pathSum;

    // Return max gain if continuing through this node (can only go one direction)
    int bestBranch = leftGain > rightGain ? leftGain : rightGain;
    return node->val + bestBranch;
}

int maxPathSum(struct TreeNode *root) {
    globalMax = INT_MIN;
    maxGain(root);
    return globalMax;
}

// Helper to create a tree node
struct TreeNode *newNode(int val) {
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

int main(void) {
    // Tree: 1 -> left:2, right:3
    struct TreeNode *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    printf("%d\n", maxPathSum(root1)); // Expected: 6  (2 + 1 + 3)

    // Tree: -10 -> left:9, right:20 -> left:15, right:7
    struct TreeNode *root2 = newNode(-10);
    root2->left = newNode(9);
    root2->right = newNode(20);
    root2->right->left = newNode(15);
    root2->right->right = newNode(7);
    printf("%d\n", maxPathSum(root2)); // Expected: 42  (15 + 20 + 7)

    // Free trees
    free(root1->left); free(root1->right); free(root1);
    free(root2->right->left); free(root2->right->right);
    free(root2->right); free(root2->left); free(root2);

    return 0;
}
