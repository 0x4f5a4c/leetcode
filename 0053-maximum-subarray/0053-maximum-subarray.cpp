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