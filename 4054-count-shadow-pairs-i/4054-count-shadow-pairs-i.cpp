class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> st;

        for (int j = 0; j < n; ++j) {
            while (!st.empty() && nums[st.back()] > nums[j]) st.pop_back();

            auto it = lower_bound(st.begin(), st.end(), nums[j], 
                [&](int idx, int val) {
                    return nums[idx] < val;
                });

            ans += distance(st.begin(), it);
            st.push_back(j);
        }

        return ans;
    }
};