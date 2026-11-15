class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n+1, 0);

        for (int i = n-1; i >= 0; --i) {
            long long take1_sum = nums[i];
            long long next_diff = dp[i+1];
            long long option1;

            if (take1_sum % 3 == 0) option1 = take1_sum - next_diff;
            else option1 = take1_sum + next_diff;

            long long option2 = -1e18;
            if (i + 1 < n) {
                long long take2_sum = (long long)nums[i] + nums[i+1];
                long long next_diff = dp[i+2];
                if (take2_sum % 3 == 0) option2 = take2_sum - next_diff;
                else option2 = take2_sum + next_diff;
            }

            dp[i] = max(option1, option2);
        }
        return dp[0];
    }
};