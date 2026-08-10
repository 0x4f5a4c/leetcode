class Solution {
public:
    int solve(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();

        int sum = 0, l = 0, count = 0;

        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};