/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse_list(ListNode *head) {
        // edge case
        if (!head || !head->next) return head;
        ListNode *new_head = reverse_list(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return new_head;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        // finding out the middle and then 
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the list
        ListNode *new_head = reverse_list(slow->next);
        ListNode *first = head, *second = new_head;
        while (first && second) {
            if (first->val != second->val) {
                reverse_list(new_head);
                return false;
            }
            first  = first->next;
            second = second->next;
        }

        reverse_list(new_head);
        return true;
    }
};