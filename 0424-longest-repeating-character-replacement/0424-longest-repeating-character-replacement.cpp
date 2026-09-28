// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * Optimize version
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, max_len = 0, max_freq = 0;
        vector<int> hash(26, 0);

        while (r < n) {
            hash[s[r] - 'A']++;
            max_freq = max(max_freq, hash[s[r] - 'A']);
            if ((r - l + 1) - max_freq > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            if ((r - l + 1) - max_freq <= k) max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};
