// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zero_count = 0;
        int non_zero_product = 1;
        for (int x : nums) {
            if (x == 0) {
                zero_count++;
            } else {
                non_zero_product *= x;
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (zero_count > 1) {
                ans[i] = 0;
            } else if (zero_count == 1) {
                ans[i] = (nums[i] == 0) ? non_zero_product : 0;
            } else {
                ans[i] = non_zero_product / nums[i];
            }
        }

        return ans;
    }
};