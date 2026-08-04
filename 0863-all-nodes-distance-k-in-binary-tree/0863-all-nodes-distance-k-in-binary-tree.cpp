/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root) {
        if (!root) return;
        if (root->left != nullptr) 
            parent[root->left] = root;
        inorder(root->left);

        if (root->right != nullptr)
            parent[root->right] = root;
        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int> &ans) {
        queue<TreeNode*> que;
        unordered_set<int> visited;

        que.push(target);
        visited.insert(target->val);

        while (!que.empty()) {
            int sz = que.size();
            
            if (k == 0) break;

            while (sz--) {
                TreeNode* curr = que.front();
                que.pop();

                // left
                if (curr->left != nullptr && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }

                // right
                if (curr->right != nullptr && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }

                // parent
                if (parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            ans.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        vector<int> ans;
        inorder(root);  // populate the parent

        BFS(target, k, ans);

        return ans;
    }
};