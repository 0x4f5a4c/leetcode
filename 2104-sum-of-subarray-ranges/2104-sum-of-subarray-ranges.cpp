class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int maxVal = nums[i], minVal = nums[i];

            for (int j = i; j < n; ++j) {
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);
                ans += (maxVal - minVal);
            }
        }

        return ans;
    }
};