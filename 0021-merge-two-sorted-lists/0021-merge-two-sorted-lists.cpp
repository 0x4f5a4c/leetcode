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
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        if (!L1) return L2;
        if (!L2) return L1;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        ListNode* t1 = L1;
        ListNode* t2 = L2;

        while (t1 && t2) {
            if (t1->val == t2->val) {
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            } else if (t1->val < t2->val) {
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
            } else {
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }
        }

        if (!t1) temp->next = t2;
        if (!t2) temp->next = t1;

        return dummyNode->next;
    }
};


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next =list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (!list1) tail->next = list2;
        if (!list2) tail->next = list1;
        return dummy.next;
    }
};
