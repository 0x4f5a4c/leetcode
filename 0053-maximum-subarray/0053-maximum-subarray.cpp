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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = INT_MIN;
        int curr_sum = 0;
        for (int x : nums) {
            curr_sum += x;
            max_val = max(curr_sum, max_val);
            if (curr_sum < 0) curr_sum = 0;
        }

        return max_val;
    }
};
