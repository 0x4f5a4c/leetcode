// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

/**
 * another approach using DFS
 * @details complexities
 * space - O(h)
 * time  - O(n)
 */


class Solution {
public:
    int solve(TreeNode *node) {
        if (!node) return 0;
        int min_left  = solve(node->left);
        int min_right = solve(node->right);

        if (!node->left && !node->right) return 1;
        if (!node->left) return 1 + min_right;
        if (!node->right) return 1 + min_left;

        return min(min_left, min_right) + 1;
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return solve(root);
    }
};
