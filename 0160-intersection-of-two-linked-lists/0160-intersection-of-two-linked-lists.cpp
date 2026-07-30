/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// better then before
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *l1 = headA;
        ListNode *l2 = headB;

        while (l1 != l2) {
            l1 = (!l1) ? headB : l1->next;
            l2 = (!l2) ? headA : l2->next;
        }

        return l1;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int s1 = 0, s2 = 0;

        while (p1) {
            s1++;
            p1 = p1->next;
        }

        while (p2) {
            s2++;
            p2 = p2->next;
        }

        // get back to head
        p1 = headA;
        p2 = headB;
        if (s1 > s2) {
            for (int i = 0; i < abs(s1-s2); ++i) {
                p1 = p1->next;
            }
        } else if (s2 > s1) {
            for (int i = 0; i < abs(s1-s2); ++i) {
                p2 = p2->next;
            }
        }

        while (p1 && p2) {
            if (p1->val == p2->val && p1 == p2) {
                return p1;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return nullptr;
    }
};
