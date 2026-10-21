// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, vector<int> &vec) {
        if (!node) return;
        solve(node->left, vec);
        if (!node->left && !node->right) vec.push_back(node->val);
        solve(node->right, vec);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return false;
        vector<int> vec1, vec2;
        solve(root1, vec1);
        solve(root2, vec2);

        if (vec1.size() != vec2.size()) return false;
        for (int i = 0; i < vec1.size(); ++i) {
            if (vec1[i] != vec2[i]) return false;
        }

        return true;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();