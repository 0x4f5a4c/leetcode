class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> children(n);

        for (int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);

        vector<int> depth(n, 0);
        long long total_nums = 0, sum_depth_weight = 0;

        int h = 0;

        // bfs traversal
        queue<pair<int, int>> que;
        que.push({0, 1});
        depth[0] = 1;

        while (!que.empty()) {
            auto [u, d] = que.front();
            que.pop();
            depth[u] = d;
            h = max(h, d);
            total_nums += nums[u];
            sum_depth_weight += 1LL * nums[u] * d;

            for (int v : children[u])
                que.push({v, d + 1});
        }

        long long ans = (h + 1LL) * total_nums - sum_depth_weight;
        return ans;
    }
};