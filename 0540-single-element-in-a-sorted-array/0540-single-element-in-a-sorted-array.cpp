class Solution {
public:
    static int solve(vector<int> &nums, int low, int high) {
        if (low == high) return nums[low];
        int mid = low + (high - low) / 2;
        if (mid % 2 == 1) mid--;
        if (nums[mid] == nums[mid+1]) return solve(nums, mid+2, high);
        else return solve(nums, low, mid);
    }

    static int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        return solve(nums, low, high);    
    }
};