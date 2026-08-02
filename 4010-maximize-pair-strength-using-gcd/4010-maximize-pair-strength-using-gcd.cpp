class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long a = nums[i];
                long long b = nums[j];
                long long g = gcd(a, b);
                long long strength = (a / g) * (b / g);
                ans = max(ans, strength);
            }
        }

        return ans;
    }
};