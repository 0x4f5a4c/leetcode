// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// this is my initial thoughts on this problem, I will try to solve it using hashing and sorting
/**
 * @time_complexity O(n * k log k) where n is the number of strings and k is the maximum length of a string
 * @space complexity O(n * k) where n is the number of strings and k is the maximum length of a string
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        for (auto &p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
