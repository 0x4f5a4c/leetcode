// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// Question Link : https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // recursive solution
        if (!root) return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();