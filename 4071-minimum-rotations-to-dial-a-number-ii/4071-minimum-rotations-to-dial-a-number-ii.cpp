class Solution {
public:
    int minRotations(int n, string s) {
        // lambda function to compute the distance between two characters
        auto get_dist = [](char a, char b) {
            int diff = std::abs((a - '0') - (b - '0'));
            return std::min(diff, 10 - diff);
        };

        int base_cost = get_dist('0', s[0]);
        for (int i = 1; i < n; ++i) {
            base_cost += get_dist(s[i-1], s[i]);
        }

        int mini_total = base_cost;

        for (int k = 0; k < n; ++k) {
            int old_transaction_cost, new_transaction_cost;
            if (k == 0) {
                old_transaction_cost = get_dist('0', s[0]);
                new_transaction_cost = get_dist('0', s[n-1]);
            } else {
                old_transaction_cost = get_dist(s[k-1], s[k]);
                new_transaction_cost = get_dist(s[k-1], s[n-1]);
            }

            int cost_with_reversal = base_cost - old_transaction_cost + new_transaction_cost;
            mini_total = std::min(mini_total, cost_with_reversal);
        }

        return mini_total;
    }
};