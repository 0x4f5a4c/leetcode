class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for (int x : nums) {
            string res;
            for (int k = 25; k >= 0; k--) {
                long long p = 1LL << k;
                if (x >= p) {
                    int cnt = x/p;
                    x %= p;
                    res.append(cnt, char('a' + k));
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};