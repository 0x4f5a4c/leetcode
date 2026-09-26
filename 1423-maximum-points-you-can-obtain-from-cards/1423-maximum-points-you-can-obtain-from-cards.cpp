// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n = points.size();
        if (n == 0) return 0;
        if (n == k) return accumulate(points.begin(), points.end(), 0);

        int left_sum = 0, max_point = 0;
        for (int i = 0; i < k; ++i) left_sum += points[i];
        max_point = left_sum;
        
        int right_sum = 0, right_idx = n-1;
        for (int i = k-1; i >= 0; --i) {
            left_sum -= points[i];
            right_sum += points[right_idx];
            right_idx--;

            max_point = max(max_point, left_sum + right_sum);
        }

        return max_point;
    }
};