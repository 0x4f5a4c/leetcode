// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_attacked(int i, int j, vector<string>& cur) {
        int n = cur.size();
        // check upper columns
        for(int k = 0; k < i; k++) 
            if(cur[k][j] == 'Q') return true;

        // check upper diagonals only
        int l = i, r = j;
        while(l >= 0 && r >= 0) 
            if(cur[l--][r--] == 'Q') return true;

        l = i, r = j;
        while(l >= 0 && r < n) 
            if(cur[l--][r++] == 'Q') return true;

        return false;
    }

    void solve(int row, vector<string>& cur, vector<vector<string>>& ans) {
        if(row == cur.size()) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < cur.size(); i++) {
            if(!is_attacked(row, i, cur)) {
                cur[row][i] = 'Q';
                solve(row + 1, cur, ans);
                cur[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> cur(n, s);
        solve(0, cur, ans);
        return ans;
    }
};