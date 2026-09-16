// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// brute force approach
class Solution {
public:
    // modified approach
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        int n = nums.size();
        for (int num : nums) {
            if (seen[num] > 0) {
                return true;
            }
            seen[num]++;
        }
        return false;
    }
};