class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, int>, int> count;
        int base = 0;

        for (int i = 0; i < n-1; ++i) {
            int x = nums[i];
            int y = nums[i + 1];

            if (x == y) base++;
            else {
                count[{x, y}]++;
                count[{y, x}]++;
            }
        }

        int best = 0;
        for (auto &[p, freq] : count) best = max(best, freq);

        return best + base;
    }
};