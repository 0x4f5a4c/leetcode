// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

/**
 * another solution using iterative approach
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto node = q.front(); q.pop();
                if (node->left) {
                    if (!node->left->left && !node->left->right) sum += node->left->val;
                    else q.push(node->left);
                }

                if (node->right) q.push(node->right);
            }
        }

        return sum;
    }
};
