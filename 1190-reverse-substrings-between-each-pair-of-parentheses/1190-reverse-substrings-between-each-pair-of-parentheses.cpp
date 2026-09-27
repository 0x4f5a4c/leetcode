// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;


// Question Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2026-09-27

class Solution {
public:
    string reverseParentheses(string s) {
        while (true) {
            int close = -1;
            // find the first closing parenthesis 
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == ')') {
                    close = i;
                    break;
                }
            }

            if (close == -1) break;
            int open = close - 1;
            while (s[open] != '(') open--;
            reverse(s.begin() + open+1, s.begin() + close);
            s.erase(close, 1);
            s.erase(open, 1);
        }

        return s;
    }
};