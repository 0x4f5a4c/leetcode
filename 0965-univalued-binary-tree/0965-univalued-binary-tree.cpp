// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, vector<int> & nums) {
        if (!node) return;
        solve(node->left, nums);
        nums.push_back(node->val);
        solve(node->right, nums);
    }

    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        vector<int> nums;
        solve(root, nums);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) return false;
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