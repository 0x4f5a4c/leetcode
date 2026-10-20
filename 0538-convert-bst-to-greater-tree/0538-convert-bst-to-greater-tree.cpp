// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, int &sum) {
        if (!node) return;
        solve(node->right, sum);
        sum += node->val;
        node->val = sum;
        solve(node->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();