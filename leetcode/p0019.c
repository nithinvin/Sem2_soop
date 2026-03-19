// LeetCode 19 - Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode dummy = {0, head};
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // Advance fast by n+1 steps so gap between fast and slow is n
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the node to remove
    struct ListNode *toDelete = slow->next;
    slow->next = toDelete->next;
    free(toDelete);

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
    // [1,2,3,4,5], n=2 => [1,2,3,5]
    struct ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    head = removeNthFromEnd(head, 2);
    printList(head); // Expected: 1 -> 2 -> 3 -> 5

    freeList(head);
    return 0;
}
