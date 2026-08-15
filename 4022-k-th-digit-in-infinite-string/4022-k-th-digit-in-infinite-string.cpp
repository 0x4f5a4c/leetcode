class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) return k;
        long long total = 9;
        int d = 2;
        vector<long long> pow10(19, 1);
        for (int i = 1; i < 19; ++i) pow10[i] = pow10[i-1] * 10;

        while (true) {
            long long block = 9 * pow10[d-2];
            long long digit_per_block = 10LL * d;
            long long contr = block * digit_per_block;
            if (total + contr >= k) break;
            total += contr;
            ++d;
        }

        long long rem = k - total;
        long long start_block = pow10[d - 2];
        long long digit_per_block = 10LL * d;

        long long block_offset = (rem - 1) / digit_per_block;
        long long b = start_block + block_offset;

        long long pos_in_block = (rem - 1) % digit_per_block + 1;
        long long num_idx = (pos_in_block - 1) / d;
        long long digit_idx = (pos_in_block - 1) % d;

        long long val;
        if (b % 2 == 0) {
            val = 10 * b + num_idx;
        } else {
            val = 10 * b + 9 - num_idx;
        }

        string s = to_string(val);
        return s[digit_idx] - '0';
    }
};