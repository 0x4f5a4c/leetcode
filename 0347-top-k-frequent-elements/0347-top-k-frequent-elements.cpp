// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

// approach 1
// using min_heap
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int &x : nums) mpp[x]++;
        // define min heap
        priority_queue<P, vector<P>, greater<P>> pq;
        // push the elements into the min_heap and maintain the k size only

        for (auto &it : mpp) {
            int val  = it.first;
            int freq = it.second;

            pq.push({freq, val});
            if (pq.size() > k) pq.pop();
        }

        // convert the min heap into vec
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
