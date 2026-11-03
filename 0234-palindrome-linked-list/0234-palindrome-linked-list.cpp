// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode * reverse_list(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *curr = head, *prev = nullptr;

        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        // now first find the half

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) slow = slow->next;
        slow = reverse_list(slow);
        fast = head;  // reassing

        while (slow && fast) {
            if (fast->val != slow->val) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();