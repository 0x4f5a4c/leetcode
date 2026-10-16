// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link :
// https://leetcode.com/problems/recover-binary-search-tree/description/

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    void inorder(TreeNode* node) {
        if (!node)
            return;
        inorder(node->left);

        if (prev && (node->val < prev->val)) {
            if (first == nullptr) {
                first = prev;
                middle = node;
            } else
                last = node;
        }

        prev = node;
        inorder(node->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        // prev = new TreeNode(INT_MIN);
        prev = nullptr;
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }

private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
};