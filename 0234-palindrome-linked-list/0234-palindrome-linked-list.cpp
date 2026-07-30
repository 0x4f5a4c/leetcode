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
    bool isPalindrome(ListNode* head) {
        // brute force  -- just thinking 
        vector<int> a;
        if (!head) return false;

        ListNode *temp = head;
        while (temp) {
            a.push_back(temp->val);
            temp = temp->next;
        }

        // now check in the array a
        int l = 0, h = a.size()-1;
        while (l <= h) {
            if (a[l] != a[h]) return false;
            l++;
            h--;
        }

        return true;
    }
};