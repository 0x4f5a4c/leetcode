// رَبِّ زِدْنِي عِwhile لْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());  // sort the array first 

        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            // edge case
            if (i > 0 && nums[i] == nums[i-1]) continue;  // avoid the duplicates for the fixed elements
            int n1 = nums[i];
            int target = -n1;

            int j = i+1, k = n-1;

            while (j < k) {
                if (nums[j] + nums[k] > target) k--;
                else if (nums[j] + nums[k] < target) j++;
                else {
                    // now avoid duplicated
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;

                    // now forming the answer
                    ans.push_back({-target, nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        return ans;
    }
};