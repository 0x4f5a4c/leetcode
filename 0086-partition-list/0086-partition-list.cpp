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
    ListNode* partition(ListNode* head, int x) {
        // brute force
        // take the values into one array
        // sort the array
        // form a new linked list from array and return the head of the new list
        // time complexity : O(N)
        // space complexity : O(1)
        if (!head) return nullptr;
        
        ListNode dummy(-1);
        ListNode *curr = &dummy;

        ListNode *temp = head;
        while (temp) {
            if (temp->val < x) {
                ListNode *newNode = new ListNode(temp->val);
                curr->next = newNode;
                curr = curr->next;
            }
            temp = temp->next;
        }

        temp = head;  // again do the same but for val >= x

        while (temp) {
            if (temp->val >= x) {
                ListNode *newNode = new ListNode(temp->val);
                curr->next = newNode;
                curr = curr->next;
            }
            temp = temp->next;
        }

        return dummy.next;
    }
};