// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;


// Question Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2026-09-27

class Solution {
public:
    string reverseParentheses(string s) {

        int n = s.size();

        vector<int> pair(n);
        stack<int> st;

        // find matching parentheses
        for (int i = 0; i < n; ++i) {

            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {

                int j = st.top();
                st.pop();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans;

        int i = 0;
        int direction = 1;

        while (i < n) {

            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            }
            else 
                ans += s[i];

            i += direction;
        }

        return ans;
    }
};