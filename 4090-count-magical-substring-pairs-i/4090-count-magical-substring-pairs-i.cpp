#include <iostream>
using namespace std;

#define vi vector<long long>
#define ll long long

class Solution {
public:
    vector<long long> count_at_most(const string &s, int limit) {
        int n = s.size();
        vector<long long> at_most(n, 0);
        if (limit == 0) return at_most;

        unordered_map<char, int> freq;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            freq[s[right]]++;
            while (freq.size() > limit) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            at_most[right] = right - left + 1;
        }

        return at_most;
    }
    
    int countMagicalPairs(string s) {
        int n = s.size();
        int total_pairs = 0;
        for (int d = 1; d <= 26; ++d) {
            vi left_at_most = count_at_most(s, d);
            vi left_at_most_minus_1 = count_at_most(s, d-1);
            vi left_exactly_d(n, 0);

            for (int i = 0; i < n; ++i) left_exactly_d[i] = left_at_most[i] - left_at_most_minus_1[i];
            string _reversed = s;
            reverse(_reversed.begin(), _reversed.end());

            vi right_at_most_d_rev = count_at_most(_reversed, d);
            vi right_at_most_d_minus_1_rev = count_at_most(_reversed, d - 1);

            vi right_exactly_d(n, 0);
            for (int i = 0; i < n; ++i) {
                ll at_most_d = right_at_most_d_rev[n-i-1];
                ll at_most_d_minus1 = right_at_most_d_minus_1_rev[n-i-1];
                right_exactly_d[i] = at_most_d - at_most_d_minus1;
            }

            for (int j = 0; j < n-1; ++j) {
                total_pairs += left_exactly_d[j] * right_exactly_d[j+1];
            }
        }

        return total_pairs;
    }
};