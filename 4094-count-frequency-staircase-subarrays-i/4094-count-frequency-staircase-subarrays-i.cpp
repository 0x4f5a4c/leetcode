#define ll long long
#define vi vector<int> 

class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            vi distinct_order;

            for (int j = i; j < n; ++j) {
                if (freq[nums[j]] == 0) distinct_order.push_back(nums[j]);
                freq[nums[j]]++;
                bool is_valid = true;
                for (int k = 0; k < distinct_order.size(); ++k) {
                    if (freq[distinct_order[k]] != k+1) {
                        is_valid = false;
                        break;
                    }
                }

                if (is_valid) ans++;
            }
        }

        return ans;
    }
};