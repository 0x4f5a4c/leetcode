// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

class Solution {
public:
    int solve(TreeNode *node, int &dia) {
        if (!node) return 0;
        int lh = solve(node->left, dia);
        int rh = solve(node->right, dia);

        dia = max({dia, lh + rh});
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        solve(root, dia);
        return dia;
    }
    
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();