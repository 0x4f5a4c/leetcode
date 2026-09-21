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

// using approach 2
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

