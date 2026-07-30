class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8) return n;
        int sz = n/8;
        int rem = n % 8;
        int ans = 0;
        for (int i = 1; i <= sz; ++i) {
            ans += i * 8;
        }
        if (rem == 0) return ans;
        ans = ans + (sz + 1) * rem;
        return ans;
    }
};