class Solution {
public:
    const int MAXV = 500;
    int maxSubarray(vector<int>& nums) {
        vector<int> freq(MAXV+1, 0);
        vector<int> pair_sum(2 * MAXV + 1, 0);
        int left = 0, ans = 0, n = nums.size();

        for (int right = 0; right < n; ++right) {
            int x = nums[right];
            bool invalid = false;

            if (pair_sum[x] > 0) invalid = true;
            if (!invalid) {
                for (int y = 1; y <= MAXV; ++y) {
                    if (freq[y] > 0 && x + y <= MAXV && freq[x + y] > 0) {
                        invalid = true;
                        break;
                    }
                }
            }

            while (invalid) {
                int remove = nums[left];
                freq[remove]--;
                
                for (int y = 1; y <= MAXV; ++y) {
                    pair_sum[remove + y] -= freq[y];
                }

                left++;

                invalid = false;

                // now checking again
                if (pair_sum[x] > 0) invalid = true;
                if (!invalid) {
                    for (int y = 1; y <= MAXV; ++y) {
                        if (freq[y] > 0 && x + y <= MAXV && freq[x+y] > 0) {
                            invalid = true;
                            break;
                        }
                    }
                }
            }

            for (int y = 1; y <= MAXV; ++y) pair_sum[x + y] += freq[y];
            freq[x]++;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};