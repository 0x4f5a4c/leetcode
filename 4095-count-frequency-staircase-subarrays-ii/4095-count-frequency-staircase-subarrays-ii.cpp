#define vi vector<int> 
#define ll long long
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vi next_pos(n, -1);
        vi last_occ(100001, -1);

        for (int i = n-1; i >= 0; --i) {
            next_pos[i] = last_occ[nums[i]];
            last_occ[nums[i]] = i;
        }

        vi next_diff(n, n);
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] != nums[i+1]) next_diff[i] = i + 1;
            else next_diff[i] = next_diff[i+1];
        }

        ll ans = 0;
        vi seen(100001, -1);

        for (int L = 0; L < n; ++L) {
            ans++;
            seen[nums[L]] = L;

            int limit = (next_pos[L] == -1) ? n : next_pos[L];
            int last_idx = L;

            for (int k = 2; ; k++) {
                int idx = last_idx + 1;
                while (idx < n && seen[nums[idx]] == L) idx = next_diff[idx];

                if (idx >= n) break;

                seen[nums[idx]] = L;

                int curr = idx;
                bool possible = true;

                for (int step = 1; step < k; ++step) {
                    curr = next_pos[curr];
                    if (curr == -1) {
                        possible = false;
                        break;
                    }
                }

                if (!possible) break;

                if (curr >= limit) break;
                int temp_idx = idx + 1;
                while (temp_idx <= curr && seen[nums[temp_idx]] == L) temp_idx = next_diff[temp_idx];

                if (temp_idx > curr) {
                    ans++;
                    if (next_pos[curr] != -1) limit = min(limit, next_pos[curr]);
                }

                last_idx = idx;
            }
        }

        return (int)ans;
    }
};