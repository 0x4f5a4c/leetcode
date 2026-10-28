// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    void permutation(int idx, vector<int> &nums, vector<vector<int>> &ans) {
        if (idx >= n) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < n; ++i) {
            swap(nums[i], nums[idx]);
            permutation(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;

        permutation(0, nums, ans);
        return ans;
    }
};