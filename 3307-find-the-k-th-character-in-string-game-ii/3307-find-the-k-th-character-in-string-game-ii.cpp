// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) return 'a';
        long long length = 1;
        long long idx = -1;
        int operation_type = -1;
        int n = operations.size();

        for (int i = 0; i < n; ++i) {
            length *= 2;
            if (length >= k) {
                operation_type = operations[i];
                idx = k - length/2;
                break;
            }
        }

        char ch = kthCharacter(idx, operations);
        if (operation_type == 0) return ch;
        return (ch == 'z') ? 'a' : ch + 1;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();