
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (!is_sorted(nums.begin(), nums.end())) {
            int n = nums.size();
            int min_val = INT_MAX;
            int idx = 0;
            count++;

            for (int i = 0; i < n - 1; ++i) {
                if (nums[i] + nums[i + 1] < min_val) {
                    min_val = nums[i] + nums[i + 1];
                    idx = i;
                }
            }

            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                if (i != idx)
                    ans.push_back(nums[i]);
                else {
                    ans.push_back(min_val);
                    i++;
                }
            }

            nums = ans;
        }

        return count;
    }
};

// -------------------------- Another way -------------------------- //
class Solution {
private:
    bool isSorted(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0, n = nums.size();
        while(!isSorted(nums, n)) {
            ans += 1;
            int min_sum = INT_MAX, pos = -1;
            for(int i = 1; i < n; i++) {
                int sum = nums[i - 1] + nums[i];
                if(sum < min_sum) {
                    min_sum = sum;
                    pos = i;
                }
            }
            nums[pos - 1] = min_sum;
            for(int i = pos; i < n - 1; i++) nums[i] = nums[i + 1];
            n--;
        }
        return ans;
    }
};
