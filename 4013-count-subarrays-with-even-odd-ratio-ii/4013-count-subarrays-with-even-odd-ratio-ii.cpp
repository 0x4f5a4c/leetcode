class Help {
    vector<long long> bit;
    int n;
public:
    Help(int n) : n(n), bit(n+1, 0) {}
    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    long long sum(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }

        return res;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) {
            long long w = (nums[i] % 2 == 0) ? (long long)b : -(long long)a;
            pref[i+1] = pref[i] + w;
        }

        vector<long long> val = pref;
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        int m = val.size();

        auto getRank = [&](long long x) {
            return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
        };

        Help bit(m);
        bit.add(getRank(pref[0]), 1);

        long long ans = 0;
        for (int j = 1; j <= n; ++j) {
            int r = getRank(pref[j]);
            long long less = bit.sum(r - 1);
            long long total = j;
            ans += total - less;
            bit.add(r, 1);
        }

        return ans;
    }
};



