// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h";
using namespace std;

class Solution {
public:
    int check(TreeNode *node) {
        if (!node) return 0;
        int lh = check(node->left);
        if (lh == -1) return -1;  // means not balanced
        int rh = check(node->right);
        if (rh == -1) return -1;  // means not balanced
        if (abs(rh - lh) > 1) return -1; // means not balanced
        return 1 + max(lh, rh);  // let recursive decide what is trur or what is false
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();