/**
 * LeetCode 876 - Middle of the Linked List
 *
 * Given the head of a singly linked list, return the middle node.
 * If there are two middle nodes, return the second middle node.
 */

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
