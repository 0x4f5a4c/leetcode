// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// better then before 
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda_function = [&](int &a, int &b) {
            int count_one_bits_in_A = __builtin_popcount(a);
            int count_one_bits_in_B = __builtin_popcount(b);

            if (count_one_bits_in_A == count_one_bits_in_B) return a < b;
            return count_one_bits_in_A < count_one_bits_in_B;
        };

        sort(arr.begin(), arr.end(), lambda_function);
        return arr;
    }
};