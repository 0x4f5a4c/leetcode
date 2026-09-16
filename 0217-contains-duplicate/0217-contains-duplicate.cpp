// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

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

// approach 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (st.count(nums[i]) > 0) {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};
