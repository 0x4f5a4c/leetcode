class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size(), m = shifts.size();
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + tasks[i];

        vector<int> ans;
        long long idx = 0;
        long long done = 0;

        for (int shiftTime : shifts) {
            long long t = shiftTime;
            // try to fininsh current task possible 
            if (idx < n) {
                long long rem = tasks[idx] - done;
                if (t >= rem) {
                    t -= rem;
                    idx++;
                    done = 0;
                } else {
                    done += t;
                    ans.push_back(n - idx);
                    continue;
                }
            }

            if (idx < n && t > 0) {
                long long target = pref[idx] + t;
                int pos = upper_bound(pref.begin(), pref.end(), target) - pref.begin() - 1;
                long long used = pref[pos] - pref[idx];
                t -= used;
                idx = pos;
                done = 0;
            }

            if (idx == n) {
                ans.push_back(0);
                // reset
                idx = 0;
                done = 0;
            } else {
                done = t;
                ans.push_back(n - idx);
            }
        }

        return ans;
    }
};