// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/different-ways-to-add-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

const char ADDITION       = '+';
const char MULTIPLICATION = '*';
const char SUBTRACTION    = '-';

/**
 * can we improve this,
 * I think yes baby I can, let give it a try
 * and what we are improving, since we are substracting using substr(), method, we can use index insted of "substr()" method
 */

class Solution {
public:
    // from i to j -> are going to help in substricting
    vector<int> memo[21][21]; 
    vector<int> solve(string exp, int i, int j) {
        if (!memo[i][j].empty()) return memo[i][j];
        vector<int> ans;
        for (int idx = i; idx <= j; ++idx) {
            // now check the validity condition, is this match 
            if (exp[idx] == ADDITION || exp[idx] == SUBTRACTION || exp[idx] == MULTIPLICATION) {
                vector<int> left  = solve(exp, i, idx-1);  // baby kaha se kaha tk ?
                vector<int> right = solve(exp, idx+1, j);  // baby lekin kaha se kaha tk 

                for (int x : left) {
                    for (int y : right) {
                        if (exp[idx] == ADDITION) ans.push_back(x+y);
                        else if (exp[idx] == SUBTRACTION) ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(exp.substr(i, j-i+1)));
        return memo[i][j] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solve(expression, 0, n-1);
    }
};