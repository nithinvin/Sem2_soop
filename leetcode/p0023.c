// LeetCode 23 - Merge k Sorted Lists (Hard)
// You are given an array of k linked-lists, each sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.
// Approach: Divide and conquer (merge pairs), O(N log k) time.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Merge two sorted linked lists
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];

    // Repeatedly merge pairs until one list remains
    int interval = 1;
    while (interval < listsSize) {
        for (int i = 0; i + interval < listsSize; i += interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
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
    // lists = [[1,4,5],[1,3,4],[2,6]]
    struct ListNode *l1 = newNode(1);
    l1->next = newNode(4);
    l1->next->next = newNode(5);

    struct ListNode *l2 = newNode(1);
    l2->next = newNode(3);
    l2->next->next = newNode(4);

    struct ListNode *l3 = newNode(2);
    l3->next = newNode(6);

    struct ListNode *lists[] = {l1, l2, l3};
    struct ListNode *merged = mergeKLists(lists, 3);

    // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
    printList(merged);
    freeList(merged);

    return 0;
}
