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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *curr = root;
        TreeNode *tail = nullptr;

        while (curr) {
            tail = curr;
            if (curr->val == val) return root;  // means that the value is already present in the tree
            else if (val < curr->val) 
                curr = curr->left;  // means value should be be in the left side
            else 
                curr = curr->right;
        }

        TreeNode *temp = new TreeNode(val);
        if (val > tail->val)
            tail->right = temp;
        else
            tail->left = temp;

        return root;
    }
};