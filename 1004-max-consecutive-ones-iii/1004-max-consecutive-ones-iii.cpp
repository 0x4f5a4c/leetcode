// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zero_count = 0;
        int max_ones = 0;

        while (r < n) {
            if (nums[r] == 0) zero_count++;
            while (zero_count > k) {
                if (nums[l] == 0) zero_count--;
                l++;
            }
            if (zero_count <= k) 
                max_ones = max(max_ones, r - l + 1);
            r++;
        }

        return max_ones;
    }
};