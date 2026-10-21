// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, vector<int> &nums) {
        if (!node) return;
        solve(node->left, nums);
        nums.push_back(node->val);
        solve(node->right, nums);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        vector<int> nums;
        solve(root, nums);
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        if (nums.size() < 2) return -1;
        return nums[1];
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();