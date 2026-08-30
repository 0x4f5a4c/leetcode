class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int x : nums) {
            vector<pair<int, int>> options;
            // or ye multiplication hai 
            int val = x;
            int cost = 0;

            while (val <= sum) {
                options.push_back({val, cost});
                if (val > sum / 2) break;
                val *= 2;
                cost++;
            }

            // haa bhai ye divison hai 
            val = x;
            cost = 0;

            while (val > 0) {
                val /= 2;
                cost ++;
                if (val == 0) break;
                options.push_back({val, cost});
            }

            vector<int> new_dp = dp;  // thora mehanga operation hogs yaha copy krne me 
            for (int s = 0; s <= sum; ++s) {
                if (dp[s] == INF) continue;
                for (auto [val, operations] : options) {
                    if (s + val <= sum) {
                        new_dp[s + val] = min(new_dp[s + val], dp[s] + operations);
                    }
                }
            }

            dp = new_dp;
        }

        if (dp[sum] == INF) return -1;
        return dp[sum];
    }
};