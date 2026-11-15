class Solution {
public:

    long long dfs(int u, const vector<vector<int>> &children, const vector<int> &op, const vector<int> &score) {
        if (children[u].empty()) return score[u];
        long long sum_children = 0;
        long long min_child_dp = 1e18;

        for (int v : children[u]) {
            long long child_dp = dfs(v, children, op, score);
            sum_children += child_dp;
            min_child_dp = min(min_child_dp, child_dp);
        }

        if (op[u] == 1) return score[u] + sum_children - min_child_dp;
        else return score[u] + sum_children - min(0LL, min_child_dp);
    }
    
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) children[parent[i]].push_back(i);
        return dfs(0, children, op, score);
    }
};