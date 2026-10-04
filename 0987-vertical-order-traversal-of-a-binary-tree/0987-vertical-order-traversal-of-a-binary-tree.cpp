/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;  // <node, <verticle, level>>

        todo.push({root, {0, 0}});  // the very first node means root is pushed

        while (!todo.empty()) {
            auto t = todo.front();
            todo.pop();

            TreeNode *node = t.first;
            int verticle = t.second.first;
            int level    = t.second.second;

            nodes[verticle][level].insert(node->val);

            if (node->left) todo.push({node->left, {verticle - 1, level + 1}});
            if (node->right) todo.push({node->right, {verticle + 1, level + 1}});
        }

        vector<vector<int>> ans;

        for (auto p : nodes) {
            vector<int> cols;
            for (auto q : p.second) {
                cols.insert(cols.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(cols);
        }

        return ans;
    }
};