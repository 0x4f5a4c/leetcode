// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        int a = 0, b = 0, c = 0;

        for (int i = n - 1; i >= 0; --i) {
            int res = INT_MIN;
            res = max(res, stones[i] - a);
            if (i + 2 <= n)
                res = max(res, stones[i] + stones[i+1] - b);
            if (i + 3 <= n)
                res = max(res, stones[i] + stones[i+1] + stones[i+2] - c);
            
            c = b;
            b = a;
            a = res;
        }

        if (a < 0) return "Bob";
        else if (a > 0) return "Alice";
        return "Tie";
    }
};