class Solution {
public:
    // guess to brute force 
    // time complexity : O(n) + O(n)
    // space complexity : O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;  // [element, count]
        int n = nums.size();
        // O(n)
        for (int i = 0; i < n; ++i) {
            mpp[nums[i]]++;    
        }

        int ans;
        // O(n)
        for (auto data : mpp) {
            if (data.second > n/2) {
                ans = data.first;
                break;
            }
        }

        return ans;
    }
};