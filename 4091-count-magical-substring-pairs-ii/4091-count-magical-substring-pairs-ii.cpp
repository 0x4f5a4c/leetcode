#include <iostream>
using namespace std;

#define vi vector<int>
#define ll long long


class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        ll total_pairs = 0;
        
        vector<array<int, 26>> next_occ(n+1);
        next_occ[n].fill(n);
        for (int i = n-1; i >= 0; --i) {
            next_occ[i] = next_occ[i+1];
            next_occ[i][s[i] - 'a'] = i;
        }

        
        vi last_occ(26, -1);
        int P[30], N[30];
        for (int j = 0; j < n-1; ++j) {
            
            last_occ[s[j] - 'a'] = j;
            int p_size = 0;
            P[p_size++] = j;
            for (int c = 0; c < 26; ++c) {
                if (last_occ[c] != -1 && last_occ[c] != j) P[p_size++] = last_occ[c];
            }

            sort(P, P+p_size, greater<int>());
            P[p_size++] = -1;

            int n_size = 0;
            for (int c = 0; c < 26; ++c) {
                int v = next_occ[j+1][c];
                if (v < n) N[n_size++] = v;
            }

            sort(N, N+n_size);
            N[n_size++] = n;

            int max_d = min(p_size, n_size) - 1;
            for (int d = 1; d <= max_d; ++d) {
                total_pairs += (long long)(P[d-1] - P[d]) * (N[d] - N[d-1]);
            }
        }

        return total_pairs;
    }
};