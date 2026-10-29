// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int left, int right) {
        if (left + right == n+1) return {1, 1};

        // corner case
        if (left > n - right + 1) {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        // case 1, when both players are on the left hand side
        // case 2, when both players are on opposite side
        int earliest = n;
        int latest   = 1;
        int next_round_players = (n+1)/2;

        if (right <= next_round_players) {
            int count_left = left - 1;
            int mid_count = right - left - 1;

            for (int survivor_left = 0; survivor_left <= count_left; ++survivor_left) {
                for (int survivor_mid = 0; survivor_mid <= mid_count; ++survivor_mid) {
                    int next_position_P1 = survivor_left + 1;
                    int next_position_P2 = next_position_P1 + survivor_mid + 1;

                    vector<int> temp_ans = earliestAndLatest(next_round_players, next_position_P1, next_position_P2);
                    
                    earliest = min(earliest, temp_ans[0]+1);
                    latest   = max(latest, temp_ans[1] + 1);
                }
            }

        } else {
            // means this is the case 2
            int fights_with_right = n - right + 1;
            int count_left = left - 1;
            int mid_count = fights_with_right - left - 1;
            int remain_min_count = right - fights_with_right - 1;

            for (int survivor_left = 0; survivor_left <= count_left; survivor_left++) {
                for (int survivor_mid = 0; survivor_mid <= mid_count; survivor_mid++) {
                    int next_position_P1 = survivor_left + 1;
                    int next_position_p2 = next_position_P1 + survivor_mid + ((remain_min_count + 1) / 2) + 1;

                    vector<int> temp_ans = earliestAndLatest(next_round_players, next_position_P1, next_position_p2);
                    
                    earliest = min(earliest, temp_ans[0] + 1);
                    latest   = max(latest, temp_ans[1] + 1);
                }
            }
        }

        return {earliest, latest};
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();