// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
// #include "../TreeNode.h"
using namespace std;

/**
 * Another approach using Iterative DFS Code
 * @details complexities
 * Time  - O(n)
 * Space - O(h) and in best case if tree is perfect balanced tree then space is O(log n)
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, bool>> st;
        int sum = 0;
        st.push({root, false});  // because tree is not the left leaf node
        while (!st.empty())         {
            auto [node, is_left] = st.top(); st.pop();

            if (!node->left && !node->right && is_left) {
                sum += node->val;
                continue;
            }

            if (node->right)
                st.push({node->right, false});
            if (node->left)
                st.push({node->left, true});
        }

        return sum;
    }
};