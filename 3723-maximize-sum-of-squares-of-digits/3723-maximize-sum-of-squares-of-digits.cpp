// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximize-sum-of-squares-of-digits/?envType=daily-question&envId=2026-10-14

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9)
            return "";
        
        int nines  = sum/9;
        int remain = sum%9;

        string result(nines, '9');

        if(remain > 0) {
            result.push_back(remain + '0');
        }

        result.append(num - result.length(), '0');

        return result;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();