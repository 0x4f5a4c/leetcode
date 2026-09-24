// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * brute force using
 * extra space
 */
class Solution {
public:

    void _compute_buy_day(vector<int> &arr, vector<int> &price, int n) {
        arr.resize(n);
        arr[0] = INT_MAX;
        for (int i = 1; i < n; ++i) arr[i] = min(arr[i-1], price[i-1])   ;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // computing the best buy day for each selling day
        vector<int> best_buy;
        _compute_buy_day(best_buy, prices, n);

        // now forming the ans
        int max_profit = 0, curr_profit;
        for (int i = 0; i < n; ++i) {
            curr_profit = prices[i] - best_buy[i];
            max_profit = max(max_profit, curr_profit);
        }
        return max_profit;
    }
};