// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1) return '0';
        int len = (1 << n) - 1;
        if (k < ceil(len / 2.0)) return findKthBit(n-1, k);
        else if (k == ceil(len / 2.0)) return '1';
        
        char ch = findKthBit(n-1, len - (k-1));
        return (ch == '0') ? '1' : '0';
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();