// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_profucts(n, 1);
        left_profucts[0] = 1;
        for (int i = 1; i < n; ++i) {
            left_profucts[i] = left_profucts[i - 1] * nums[i-1];
        }

        vector<int> right_product(n, 1);
        right_product[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            right_product[i] = right_product[i + 1] * nums[i+1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = left_profucts[i] * right_product[i];
        }
        return ans;
    }
};