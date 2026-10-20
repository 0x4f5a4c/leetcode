// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

/**
 * @details using dfs approach 
 * complexities
 * time  - O(n)
 * space - O(h)
 */

class Solution {
public:
    TreeNode *prev;
    void dfs(TreeNode *node, int &diff) {
        if (!node) return;
        if (node->left) dfs(node->left, diff);
        if (prev) {
            diff = min(diff, abs(node->val - prev->val));
        }
        prev = node;

        if (node->right) dfs(node->right, diff);
    }

    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        prev = nullptr;
        dfs(root, diff);
        return diff;
    }
};