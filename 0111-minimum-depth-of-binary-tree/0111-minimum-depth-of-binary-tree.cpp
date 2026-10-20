// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 1;   
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto curr_node = q.front(); q.pop();
                if (!curr_node->left && !curr_node->right) return depth;
                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);
            }

            depth++;
        }

        return depth;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();