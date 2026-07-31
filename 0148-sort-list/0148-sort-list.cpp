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
    ListNode* sortList(ListNode* head) {
        //  brute force approach
        // create an array and then form a new linked list from that array
        ListNode *temp = head;
        if (!head) return nullptr;

        vector<int> a;  // space O(n)
        while (temp) {
            a.push_back(temp->val);
            temp = temp->next;
        }

        sort(a.begin(), a.end());  // this will take time  // logn

        ListNode dummy(-1);
        temp = &dummy;

        for (int i = 0; i < a.size(); ++i) {  // O(n)
            ListNode *newNode = new ListNode(a[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return dummy.next;
    }

    // over all
    // time complexity : O(n * logn)
    // space complexity : O(n)
};