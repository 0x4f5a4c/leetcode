// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();