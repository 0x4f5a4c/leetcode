// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * optimal solution
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int curr_sum = nums[i] + nums[j];
            if (curr_sum < target) i++;
            else if (curr_sum > target) j--;
            else return {i+1, j+1};
        }
        return {};
    }
};
