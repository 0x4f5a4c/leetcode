class Solution {
public:
    double minPrice(vector<int>& P, vector<int>& D) {
        sort(P.rbegin(), P.rend());
        sort(D.rbegin(), D.rend());

        double ans = 0.0;
        int i = 0, j = 0;

        while (i < P.size() && j < D.size()) {
            ans += (double)P[i] * (100 - D[j]) / 100.0;
            i++;
            j++;
        }

        while (i < P.size()) {
            ans += P[i];
            ++i;
        }

        return ans;
    }
};