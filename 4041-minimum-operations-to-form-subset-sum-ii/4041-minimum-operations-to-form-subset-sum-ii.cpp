class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int x : nums) {
            vector<pair<int, int>> options;
            int curr = x;
            int div_cost = 0;

            while (curr > 0) {
                int val = curr;
                int mul_cost = 0;
                while (val <= sum) {
                    options.push_back({val, div_cost + mul_cost});
                    if (val > sum / 2) break;
                    val *= 2;
                    mul_cost++;
                }

                curr /= 2;
                div_cost++;
            }

            // bhai 0/1 knapsack
            vector<int> new_dp = dp;
            for (int s = 0; s <= sum; s++) {
                if (dp[s] == INF) continue;
                for (auto [val, cost] : options) {
                    if (s + val <= sum) new_dp[s + val] = min(new_dp[s + val], dp[s] + cost);
                }
            }
            dp = new_dp;
        }

        return (dp[sum] == INF) ? -1 : dp[sum];
    }
};