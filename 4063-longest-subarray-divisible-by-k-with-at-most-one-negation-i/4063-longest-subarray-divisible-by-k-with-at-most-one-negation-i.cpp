class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            long long curr_sum = 0;
            unordered_set<int> needed;

            for (int j = i; j < n; ++j) {
                curr_sum += nums[j];
                int sum_mod = ((curr_sum % k) + k) % k;
                int elem_mod = ((nums[j] % k) + k) % k;
                int needed_elem = (2 * elem_mod) % k;
                needed.insert(needed_elem);

                if (sum_mod == 0) max_len = max(max_len, j - i + 1);
                else if (needed.count(sum_mod)) max_len = max(max_len, j - i + 1);
            }
        }

        return max_len;
    }
};