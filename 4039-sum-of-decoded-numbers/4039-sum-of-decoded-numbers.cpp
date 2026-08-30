class Solution {
public:
    const long long MOD = 1000000007;
    long long power(long long x, long long y) {
        long long res = 1;
        while (y > 0) {
            if (y % 2 == 1)  res = res * x % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }

        return res;
    }
    
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;
            string s = to_string(d);
            long long x = stoll(s.substr(0, width));
            long long y = stoll(s.substr(width));
            long long val = power(x, y);
            ans = (ans + val) % MOD;
        }
        return (int)ans;
    }
};