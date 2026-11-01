// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
using namespace std;

/**
 * Day 1 : Novermber 2026
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(),nums.end(),0) - ((int)nums.size())*(*min_element(nums.begin(),nums.end()));
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();