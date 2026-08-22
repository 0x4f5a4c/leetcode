// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/?envType=daily-question&envId=2026-08-22

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        for (int x = n; x > 0; x /= 10) {
            const int rem = x % 10;
            sum += rem;
            product *= rem;
        }

        return n % (sum + product) == 0;
    }
};