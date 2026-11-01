// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        int mid = n/2;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < mid; i++){  // this loop is traversing till half of the array which is faster then above solution
            steps += nums[n-1-i] - nums[i]; //Adding difference
        }
        return steps;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();