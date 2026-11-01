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
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int moves = 0;
        int min_elem = nums[0];
        for (int i = n-1; i >= 1; --i) {
            moves += abs(nums[i] - min_elem);
        }

        return moves;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();