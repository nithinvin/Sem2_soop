// LeetCode 102 - Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal
// of its nodes' values (i.e., from left to right, level by level).

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 64;
    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    // BFS using a queue of tree node pointers
    int queueCap = 1024;
    struct TreeNode **queue = malloc(queueCap * sizeof(struct TreeNode *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        if (*returnSize >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(int *));
            *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
        }

        result[*returnSize] = malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *node = queue[front++];
            result[*returnSize][i] = node->val;

            if (node->left) {
                if (rear >= queueCap) {
                    queueCap *= 2;
                    queue = realloc(queue, queueCap * sizeof(struct TreeNode *));
                }
                queue[rear++] = node->left;
            }
            if (node->right) {
                if (rear >= queueCap) {
                    queueCap *= 2;
                    queue = realloc(queue, queueCap * sizeof(struct TreeNode *));
                }
                queue[rear++] = node->right;
            }
        }
        (*returnSize)++;
    }

    free(queue);
    return result;
}

// Helper to create a tree node
struct TreeNode *newNode(int val) {
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

int main(void) {
    // Tree: 3 -> left:9, right:20 -> left:15, right:7
    struct TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int returnSize;
    int *returnColumnSizes;
    int **res = levelOrder(root, &returnSize, &returnColumnSizes);

    // Expected: [[3], [9, 20], [15, 7]]
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d%s", res[i][j], j < returnColumnSizes[i] - 1 ? ", " : "");
        }
        printf("]\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);

    // Free tree
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
