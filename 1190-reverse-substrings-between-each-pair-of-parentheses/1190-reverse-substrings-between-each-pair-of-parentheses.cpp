// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;


// Question Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2026-09-27

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr;

        for (char ch : s) {
            if (ch == '(') {
                st.push(curr);
                curr.clear();
            }
            else if (ch == ')') {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};