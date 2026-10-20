// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

/**
 * @details brute force and first solution
 * complexities
 * space - O(n) + O(n) {for stack calls}
 * time  - O(2n)
 */
class Solution {
public:
    void solve(TreeNode *node, vector<int> &ans) {
        if (!node) return;
        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        vector<int> ans;
        solve(root,ans);
        int min_dist = INT_MAX;
        for (int i = 1; i < ans.size(); ++i) {
            min_dist = min(ans[i] - ans[i-1], min_dist);
        }
        return min_dist;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();