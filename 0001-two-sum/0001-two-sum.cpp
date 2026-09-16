class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            if (num_to_idx.find(complement) != num_to_idx.end()) 
                return {num_to_idx[complement], i};
            num_to_idx[nums[i]] = i;
        }

        return {};
    }
};