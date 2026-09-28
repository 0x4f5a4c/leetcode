// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * better solution -- two pointer
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, max_len = 0;
        int n = fruits.size();
        unordered_map<int, int> mpp;  // this will store [element, freq]
        while (r < n) {
            mpp[fruits[r]]++;
            while (mpp.size() > 2) {  // means we have more than 2 buckets
                mpp[fruits[l]]--;  // reduce the frequency
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;  // move l by one
            }

            if (mpp.size() <= 2) 
                max_len = max(max_len, r - l + 1);
            
            r++;
        }

        return max_len;
    }
};