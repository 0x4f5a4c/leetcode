// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/permutations-ii/

#include <bits/stdc++.h>
using namespace std;

/**
 * another solution
 */

class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int idx, int n) {
        if (idx == n) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for (int i = idx; i < n; ++i) {
            if (st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(nums, ans, idx+1, n);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(nums, ans, 0, n);
        return ans;
    }
};
