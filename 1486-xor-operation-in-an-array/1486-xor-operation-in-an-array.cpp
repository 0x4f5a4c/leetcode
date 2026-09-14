class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> vec(n);
        vec[0] = start;
        for (int i = 1; i < n; ++i) {
            vec[i] = start + 2 * i;
        }

        int ans = 0;
        for (int i = 0; i < vec.size(); ++i) {
            ans ^= vec[i];
        }

        return ans;
    }
};