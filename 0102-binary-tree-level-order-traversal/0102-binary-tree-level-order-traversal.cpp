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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while (sz > 0) {
                TreeNode *curr_node = q.front();
                q.pop();
                temp.push_back(curr_node->val);
                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);
                sz--;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};