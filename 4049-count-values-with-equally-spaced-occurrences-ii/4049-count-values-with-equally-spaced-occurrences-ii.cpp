class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) positions[nums[i]].push_back(i);

        int ans = 0;
        
        for (auto &it : positions) {
            vector<int> pos = it.second;
            if (pos.size() < 3) continue;
            int gap = pos[1] - pos[0];
            bool special = true;

            for (int i = 2; i < pos.size(); ++i) {
                if (pos[i] - pos[i-1] != gap) {
                    special = false;
                    break;
                }
            }

            if (special) ans++;
        }

        return ans;
    }
};