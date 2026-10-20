// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, bool is_left, int &sum) {
        if (!node) return;
        if (!node->left && !node->right && is_left) {
            sum += node->val;
            return;  // do not go further
        }

        solve(node->left, true, sum);
        solve(node->right, false, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root, false, sum);
        return sum;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();