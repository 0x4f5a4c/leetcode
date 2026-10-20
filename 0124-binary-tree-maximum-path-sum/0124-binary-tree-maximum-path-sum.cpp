// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

class Solution {
public:
    int solve(TreeNode *node, int &maxi) {
        if (!node) return 0;
        int left_sum = max(0, solve(node->left, maxi));
        int right_sum = max(0, solve(node->right, maxi));

        maxi = max(maxi, node->val + right_sum + left_sum);
        return max(left_sum, right_sum) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();