class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), max_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                max_sum = max(max_sum, ((nums[i] - 1) * (nums[j]-1)));
            }
        }

        return max_sum;
    }
};