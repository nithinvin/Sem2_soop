// LeetCode 2 - Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order. Add the two numbers and return the sum
// as a linked list.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *curr = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;

        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        curr->next = node;
        curr = node;
    }

    return dummy.next;
}

// Helper to create a node
struct ListNode *newNode(int val) {
    struct ListNode *n = malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

// Helper to print list
void printList(struct ListNode *head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Helper to free list
void freeList(struct ListNode *head) {
    while (head) {
        struct ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    // 342 + 465 = 807 => [2,4,3] + [5,6,4] = [7,0,8]
    struct ListNode *l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    struct ListNode *l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    struct ListNode *result = addTwoNumbers(l1, l2);
    printList(result); // Expected: 7 -> 0 -> 8

    freeList(l1);
    freeList(l2);
    freeList(result);
    return 0;
}
