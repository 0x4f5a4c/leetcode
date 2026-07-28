class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n * (n+1)) / 2;
        int curr_sum = 0;
        for (int i = 0; i < n; ++i) curr_sum += nums[i];

        return total_sum - curr_sum;
    }
};