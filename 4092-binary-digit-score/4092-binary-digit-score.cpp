class Solution {
public:
    int calculateScore(int a, int b) {
        int _a = __builtin_popcount(a);
        int _b = __builtin_popcount(b);

        return (_a >= _b) ? _a * _b : _b / _a;
    }
};