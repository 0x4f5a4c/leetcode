// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int k) {
        int sum = 0, l = 0, n = nums.size();
        int count = 0;

        for (int r = 0; r < n; ++r) {
            sum += (nums[r] % 2);
            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};