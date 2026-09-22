// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;


// another approach using unordered_set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int x = it;
                int count = 1;

                while (st.find(x + 1) != st.end()) {
                    x += 1;
                    count += 1;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};