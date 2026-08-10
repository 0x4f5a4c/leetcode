
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n = points.size();
        if (n == k) return accumulate(points.begin(), points.end(), 0);

        int max_sum = 0;

        for (int i = 0; i < k; ++i) max_sum += points[i];
        
        int curr_sum = max_sum;
        for (int i = k - 1; i >= 0; --i) {
            curr_sum -= points[i];
            curr_sum += points[points.size() - k + i];
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};
