class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int _min = INT_MAX;
        for (int i = 0, j = 1; i < n-1 && j < n; ++i, ++j) {
            string x = to_string(nums[i]);
            string y = to_string(nums[j]);
            string concat = x+y;
            _min = min(_min, stoi(concat));
        }

        return _min;
    }
};