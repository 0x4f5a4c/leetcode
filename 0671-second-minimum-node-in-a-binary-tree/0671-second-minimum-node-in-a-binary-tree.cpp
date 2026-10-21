// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

/**
 * another solution
 * 
 */

class Solution {
public:
    void solve(TreeNode *node, set<int> &nums) {
        if (!node) return;
        solve(node->left, nums);
        nums.insert(node->val);
        solve(node->right, nums);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        set<int> st;
        solve(root, st);
        if (st.size() <= 1) return -1;
        return *next(st.begin());
    }
};
