class Solution {
public:
    int hammingWeight(int n) {
        int no_of_bits = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1) no_of_bits += 1;
        }
        return no_of_bits;
    }
};