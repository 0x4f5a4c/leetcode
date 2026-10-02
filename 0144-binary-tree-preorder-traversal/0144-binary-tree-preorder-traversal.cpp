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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* temp = root;

        while (temp || !st.empty()) {
            if (temp) {
                ans.push_back(temp->val);
                st.push(temp);
                temp = temp->left;
            } else {
                temp = st.top();
                st.pop();
                temp = temp->right;
            }
        }

        return ans;
    }
};