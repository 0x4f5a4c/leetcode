// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1) return 0;
        int len = pow(2, n-1);
        int mid = len / 2;
        if (k <= mid) return kthGrammar(n-1, k);
        return !kthGrammar(n-1, k-mid);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();