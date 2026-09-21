// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

/**
 * Brute force solution
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i) mpp[nums[i]]++;  // it takes O(N) time traversing and space O(N) times
        // now transform this into a vector or pairs
        // where pair<int, int> stores <freq, element>

        vector<pair<int, int>> vec;
        for (auto &it : mpp) {
            vec.push_back({it.second, it.first});
        }

        sort(vec.rbegin(), vec.rend());
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};