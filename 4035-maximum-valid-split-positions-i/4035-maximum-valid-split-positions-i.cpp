class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int rem = -1; rem < n; ++rem) {
            vector<int> arr;
            for(int i = 0; i < n; ++i) {
                if (i != rem) arr.push_back(nums[i]);
            }

            int m = arr.size();
            if (m < 2) continue;

            vector<int> prefix(m);
            prefix[0] = arr[0];
            for (int i = 1; i < m; ++i) {
                prefix[i] = gcd(prefix[i-1], arr[i]);
            }

            vector<int> suffix(m);
            suffix[m-1] = arr[m-1];
            for (int i = m-2; i >= 0; --i) {
                suffix[i] = gcd(suffix[i+1], arr[i]);
            }

            int score = 0;
            for (int i = 0; i < m-1; ++i) {
                if (prefix[i] == suffix[i+1]) score++;
            }

            ans = max(ans, score);
        }

        return ans;
    }
};