// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : http://leetcode.com/problems/lexicographical-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int curr_num, int limit, vector<int> &ans) {
        if (curr_num > limit) return;
        ans.push_back(curr_num);

        for (int append = 0; append <= 9; ++append) {
            int new_num = (curr_num * 10) + append;
            if (new_num > limit) return;
            solve(new_num, limit, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        if (n <= 9) {
            for (int i = 1; i <= n; ++i) ans.push_back(i);
            return ans;  // we are directly returning from here, not going anywhere else
        }
        // if somehow the number is > 9 then we have to see
        for (int i = 1; i <= 9; ++i) solve(i, n, ans);
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();