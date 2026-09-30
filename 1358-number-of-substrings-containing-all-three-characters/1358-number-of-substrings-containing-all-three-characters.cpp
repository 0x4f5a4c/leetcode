// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<int> last_seen(3, -1);

        for (int i = 0 ; i < n; ++i) {
            last_seen[s[i] - 'a'] = i;  // updating the index
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                // means this is a valid substring
                count += (1 + min({last_seen[0], last_seen[1], last_seen[2]}));
            }
        }

        return count;
    }
};