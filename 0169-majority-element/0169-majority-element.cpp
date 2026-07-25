class Solution {
public:
    // approach 2
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting takes some time sweetheart
        int n = nums.size();
        return nums[n/2];
    }
};