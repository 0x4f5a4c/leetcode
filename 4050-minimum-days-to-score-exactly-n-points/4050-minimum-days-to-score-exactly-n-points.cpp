class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int x = 1; x <= n; ++x) {
            for (int k = 1; ; ++k) {
                int points = k * (k + 1) / 2;
                if (points > x) break;

                int remaining = x - points;
                if (remaining == 0) dp[x] = min(dp[x], k);
                else if (dp[remaining] != INT_MAX) dp[x] = min(dp[x], dp[remaining] + 1 + k);
                
            }
        }

        return dp[n];
    }
};