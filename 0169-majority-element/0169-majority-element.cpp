// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @details this solution is my initial thinking
     * @time complexity  : O(n)
     * @space complexity : O(n)
     */

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i)
            mpp[nums[i]]++;
        for (const auto [val, freq] : mpp) {
            if (freq > n / 2) {
                return val;
            }
        }

        return -1;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();