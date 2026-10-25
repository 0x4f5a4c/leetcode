// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;


/**
 * another solution
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int _left_depth  = left_depth(root);
        int _right_depth = right_depth(root);

        if (_left_depth == _right_depth) return (1 << _right_depth) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:

    int left_depth(TreeNode *node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth++;
        }
        return depth;
    }

    int right_depth(TreeNode *node) {
        int depth = 0;
        while (node) {
            node = node->right;
            depth++;
        }

        return depth;
    }
};
