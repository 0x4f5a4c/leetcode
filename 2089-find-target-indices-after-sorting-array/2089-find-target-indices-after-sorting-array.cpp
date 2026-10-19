// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-target-indices-after-sorting-array/?envType=daily-question&envId=2026-10-19

#include <bits/stdc++.h>
using namespace std;


/**
 * another approach of solving this 
 */

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for (int x : nums)
            if (x < target) less++;
            else if (x == target) equal++;

        vector<int> ans;
        for (int i = 0; i < equal; ++i)
            ans.push_back(less + i);
        return ans;
    }
};