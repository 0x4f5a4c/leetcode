class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), max_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                max_sum = max(max_sum, ((nums[i] - 1) * (nums[j]-1)));
            }
        }

        return max_sum;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n-1] - 1) * (nums[n-2] - 1);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (int n : nums) {
            if (n >= max1) {
                max2 = max1;
                max1 = n;
            } else if (n >= max2) {
                max2 = n;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
