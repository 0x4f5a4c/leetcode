// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // this will take log(num) time 
    int count_one_bits(int num) {
        int count = 0;
        while (num != 0) {
            count += (num & 1);
            num >>= 1;
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto lambda_function = [&](int &a, int &b) {
            int count_one_bits_in_A = count_one_bits(a);
            int count_one_bits_in_B = count_one_bits(b);

            if (count_one_bits_in_A == count_one_bits_in_B) return a < b;
            return count_one_bits_in_A < count_one_bits_in_B;
        };

        // total time complexity is : O(NlogN) + log(num)
        sort(arr.begin(), arr.end(), lambda_function);
        return arr;
    }
};