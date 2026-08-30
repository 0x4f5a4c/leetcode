class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> blocks;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) blocks[nums[i]]++;
        }
        int ans = 0;
        for (auto &[x, b] : blocks) {
            if (b == 1) ans++;
        }

        return ans;
    }
};