class Solution {
public:
    int solve(vector<int> &nums, int k) {
        if (k < 0) return 0;
        int sum = 0, l = 0, count = 0;
        int n = nums.size();
        for (int r = 0; r < n; ++r) {
            sum += (nums[r] % 2);
            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }
            count += r - l + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};