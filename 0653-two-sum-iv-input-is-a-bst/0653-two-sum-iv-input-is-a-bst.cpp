// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, vector<int> &values) {
        if (!node) return;
        solve(node->left, values);
        values.push_back(node->val);
        solve(node->right, values);
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        vector<int> values;
        solve(root, values);

        // since the values are in sorted order apply two pointer here
        int i = 0, j = values.size() - 1;

        while (i < j) {
            int curr_sum = values[i] + values[j];
            if (curr_sum == k) return true;
            else if (curr_sum < k)
                i++;
            else j--;
        }

        return false;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();