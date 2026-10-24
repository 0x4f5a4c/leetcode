class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total_subs = 0;
        int last_invalid_idx = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) last_invalid_idx = i;
            else total_subs += (i - last_invalid_idx);
        }
        return total_subs;
    }
};