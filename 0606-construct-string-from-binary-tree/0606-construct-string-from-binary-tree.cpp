// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string result = to_string(root->val);
        string left  = tree2str(root->left);
        string right = tree2str(root->right);
        
        if (!root->left && !root->right) return result;

        if (!root->left) return result + "()" + "(" + right + ")";
        if (!root->right) return result + "(" + left + ")";

        return result + "(" + left + ")" + "(" + right + ")";
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();