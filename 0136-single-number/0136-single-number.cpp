
class Solution {
public:
    // this is working but not the efficient solution
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;  // <nums, freq>

        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }

        for (auto [elem, freqency] : freq) {
            if (freqency == 1) return elem;
        }

        return -1;
    }
};