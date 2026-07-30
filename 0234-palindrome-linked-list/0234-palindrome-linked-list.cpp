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
// better then before -- reduce space complexity 
// time complexity : O(N)
// space complexity : O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // optimize solution
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            slow = slow->next;
        }

        slow = reversing(slow);
        fast = head;

        while (fast && slow) {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }

    ListNode *reversing(ListNode *slow) {
        ListNode *prev = nullptr;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        return prev;
    }
};