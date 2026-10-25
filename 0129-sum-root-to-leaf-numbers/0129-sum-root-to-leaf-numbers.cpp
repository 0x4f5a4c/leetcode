// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=problem-list-v2&envId=tree

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

/**
 * better solution
 */

class Solution {
public:
    int solve(TreeNode *node, int curr_sum) {
        if (!node) return 0;
        curr_sum = curr_sum * 10 + node->val;
        if (!node->left && !node->right) return curr_sum;
        return solve(node->left, curr_sum) + solve(node->right, curr_sum);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};