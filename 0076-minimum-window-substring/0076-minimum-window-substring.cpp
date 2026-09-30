// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        if (s.size() < t.size()) return "";

        int n = s.size();
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int starting_idx = 0;

        vector<int> freq(256, 0);

        for (char ch : t) {
            freq[ch]++;
        }

        int count = 0;
        int required = t.size();

        while (r < n) {
            if (freq[s[r]] > 0) {
                count++;
            }
            freq[s[r]]--;

            while (count == required) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    starting_idx = l;
                }

                // Remove s[l] from window
                freq[s[l]]++;
                if (freq[s[l]] > 0) {
                    count--;
                }
                l++;
            }

            r++;
        }

        return (min_len == INT_MAX) ? "" : s.substr(starting_idx, min_len);
    }
};