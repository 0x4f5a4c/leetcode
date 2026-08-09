class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) continue;
                if (i == 0 || j == 0) dp[i][j] = 1;
                else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }

        auto can = [&](int k) -> bool {
            vector<char> row_bottom(n, 0), row_top(n, 0);
            vector<char> col_right(m, 0), col_left(m, 0);

            for (int i = 0; i + k <= n; ++i) {
                for (int j = 0; j + k <= m; ++j) {
                    if (dp[i + k - 1][j + k - 1] >= k) {
                        row_bottom[i + k - 1] = 1;
                        row_top[i] = 1;
                        col_right[j + k - 1] = 1;
                        col_left[j] = 1;
                    }
                }
            }

            vector<char> pref_row(n, 0), suff_row(n + 1, 0);
            bool curr = false;
            for (int r = 0; r < n; ++r) {
                if (row_bottom[r]) curr = true;
                pref_row[r] = curr;
            }

            curr = false;

            for (int r = n-1; r >= 0; --r) {
                if (row_top[r]) curr = true;
                suff_row[r] = curr;
            }
            
            for (int r = 0; r + 1 < n; ++r) {
                if (pref_row[r] && suff_row[r + 1]) return true;
            }

            vector<char> pref_col(m, 0), suff_col(m+1, 0);
            curr = false;
            for (int c = 0; c < m; ++c) {
                if (col_right[c]) curr = true;
                pref_col[c] = curr;
            }

            curr = false;
            for (int c = m - 1; c >= 0; --c) {
                if (col_left[c]) curr = true;
                suff_col[c] = curr;
            }

            for (int c = 0; c + 1 < m; ++c) {
                if (pref_col[c] && suff_col[c + 1]) return true;
            }

            return false;
        };

        int low = 1, high = min(n, m), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans * ans;
    }
};