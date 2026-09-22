// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// better solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0 || n == 1) return n;

        int last_smallest = INT_MIN;
        int curr_count = 0, longest = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 == last_smallest) {
                curr_count += 1;
                last_smallest = nums[i];
            } else if (nums[i] != last_smallest) {
                curr_count = 1;
                last_smallest = nums[i];
            }

            longest = max(longest, curr_count);
        }

        return longest;
    }
};