// time complexity : O(N)
// space complexity : O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n * (n+1)) / 2;
        int curr_sum = 0;
        for (int i = 0; i < n; ++i) curr_sum += nums[i];

        return total_sum - curr_sum;
    }
};

// approach 2 using xor (^)
// time complexity : O(N)
// space complexity : O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n_xor = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            n_xor ^= i;
            n_xor ^= nums[i];
        }

        return n_xor;
    }
};
