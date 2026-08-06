
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06

class Solution {
public:
    int product_digit(int x) {
        int ans = 1, d = 0;
        for (; x; x /= 10) {
            d = x % 10;
            ans *= d;
        }

        return ans;
    }

    int smallestNumber(int n, int t) {
        for (int z = n; z < n + 10; ++z) {
            if (product_digit(z) % t == 0) return z;
        }

        return 0;
    }
};
