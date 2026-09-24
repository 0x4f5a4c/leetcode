// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = INT_MIN;

        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            ans = max(ans, area);

            // now which one to move
            if (height[i] < height[j]) i++;
            else j--;
        }

        return ans;
    }
};