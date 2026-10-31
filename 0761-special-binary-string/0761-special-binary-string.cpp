// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/special-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string s) {
        if (s.empty()) return "";
        vector<string> special;
        int start = 0, sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += s[i] == '1' ? 1 : -1;
            if (sum == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                special.push_back("1" + solve(inner) + "0");
                start = i + 1;
            }
        }

        sort(special.begin(), special.end(), greater<string>());
        string res;
        for (string &str : special) res += str;

        return res;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();