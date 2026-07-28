class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i-1] < 0) dp[i] = nums[i];
            else dp[i] = dp[i-1] + nums[i];
        }

        int max_elem = *max_element(dp.begin(), dp.end());
        return max_elem;
    }
};