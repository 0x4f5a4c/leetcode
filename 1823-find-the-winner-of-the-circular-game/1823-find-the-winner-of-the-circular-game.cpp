// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * fast and constant space
 */

class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + k) % i;
        }

        return ans + 1;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();