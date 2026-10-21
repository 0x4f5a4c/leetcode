// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

/**
 * optimal solution
 * @details complexities
 * time  - O(H)
 * space - O(H)
 */

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
       if (!root) return true;
       if (root->left && root->left->val != root->val) return false;
       if (root->right && root->right->val != root->val) return false;
       return isUnivalTree(root->left) && isUnivalTree(root->right); 
    }
};