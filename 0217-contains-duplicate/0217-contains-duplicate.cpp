// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;


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