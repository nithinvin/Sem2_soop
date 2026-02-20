/**
 * LeetCode 83 - Remove Duplicates from Sorted List
 *
 * Given the head of a sorted linked list, delete all duplicates
 * such that each element appears only once. Return the linked list
 * sorted as well.
 */

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
