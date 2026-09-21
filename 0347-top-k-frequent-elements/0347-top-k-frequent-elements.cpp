// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using bucket sort
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int &x : nums) mpp[x]++;
        vector<vector<int>> bucket(n+1);
        // index = frequency
        // value = element
        // bucket[i] = elements having i frequency 
        for (auto &it : mpp) {
            int elem = it.first;
            int freq = it.second;
            bucket[freq].push_back(elem);
        }

        // result 
        // pick elements from right to left from bucket to find the max frequency 
        vector<int> res;
        for (int i = n; i >= 0; --i) {
            if (bucket[i].size() == 0) continue;
            while (bucket[i].size() > 0 && k > 0) {
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return res;
    }
};
