
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = ((a | b) ^ c);
        return __builtin_popcount(res) + __builtin_popcount((a & b) & res);
    }
};