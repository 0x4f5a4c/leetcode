// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
// Question Link : https://neetcode.io/problems/find-the-punishment-number-of-an-integer/question

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int i, int curr_sum, string str, int num) {
        if (i == str.size()) return curr_sum == num;
        if (curr_sum > num) return false;

        bool possible = false;
        for (int j = i; j < str.size(); ++j) {
            string sub = str.substr(i, j-i+1);
            int val = stoi(sub);  // string to integer 

            possible = possible || check(j+1, curr_sum + val, str, num);
            
            if (possible) return true;
        }

        return possible;
    }

    int punishmentNumber(int n) {
        int punishment = 0;
        for (int num = 1; num <= n; ++num) {
            int _square = num * num;
            string str = to_string(_square);
            if (check(0, 0, str, num)) {
                punishment += _square;
            }
        }

        return punishment;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();