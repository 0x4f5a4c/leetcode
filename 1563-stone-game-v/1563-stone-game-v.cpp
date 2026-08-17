
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-v/?envType=daily-question&envId=2026-08-17

class Solution {
public:
    int stoneGameV(vector<int>& stone_value) {
        int n = stone_value.size();
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = stone_value[0];
        for (int i = 1; i < n; ++i) prefix_sum[i] = prefix_sum[i-1] + stone_value[i];

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int l = n-1; l >= 0; --l) {
            for (int r = l+1; r < n; ++r) {
                int score = 0;
                for (int mid = l; mid <= r - 1; ++mid) {
                    int left_sum  = prefix_sum[mid] - (l - 1 >= 0 ? prefix_sum[l-1] : 0);
                    int right_sum = prefix_sum[r] - prefix_sum[mid];

                    if (left_sum < right_sum) {
                        score = max(score, left_sum + dp[l][mid]);
                    } else if (left_sum > right_sum) {
                        score = max(score, right_sum + dp[mid + 1][r]);
                    } else {
                        score = max({score, left_sum + dp[l][mid], right_sum + dp[mid+1][r]});
                    }
                }

                dp[l][r] = score;
            }
        }

        return dp[0][n-1];
    }
};