class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();

        vector<vector<int>> pos(26);
        for (int i = 0; i < m; ++i) {
            pos[station[i] - 'a'].push_back(i);
        }

        vector<int> earliest(n), latest(n);

        int prev = -1;
        for (int i = 0; i < n; ++i) {
            int c = skill[i] - 'a';
            auto it = upper_bound(pos[c].begin(), pos[c].end(), prev);
            prev = *it;
            earliest[i] = prev;
        }

        int next = m;
        for (int i = n-1; i >= 0; --i) {
            int c = skill[i] - 'a';
            auto it = lower_bound(pos[c].begin(), pos[c].end(), next);
            --it;
            next = *it;
            latest[i] = next;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, latest[i + 1] - earliest[i]);
        }

        return ans;
    }
};