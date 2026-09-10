// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;  
        // now count the no of set bits in the ans
        int count = 0;
        while (ans != 0) {
            ans = (ans & ans - 1);
            count++;
        }
        return count;
    }
};