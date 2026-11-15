class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            int curr_and = nums[i];
            int curr_min = nums[i];
            
            for (int j = i; j < n; ++j) {
                if (j > i) {
                    curr_and &= nums[j];
                    curr_min = min(curr_min, nums[j]);
                }

                if (curr_and == curr_min) count++;
            }
        }

        return count;
    }
};