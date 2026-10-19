class Solution {
public:

    long long getCatalanRecursive(int n) {
        // Base case
        if (n <= 1) return 1;

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += getCatalanRecursive(i) * getCatalanRecursive(n - 1 - i);
        }
        return res;
    }

    int numTrees(int n) {
        if (n == 1) return 1;
        return static_cast<int>(getCatalanRecursive(n));
    }
};