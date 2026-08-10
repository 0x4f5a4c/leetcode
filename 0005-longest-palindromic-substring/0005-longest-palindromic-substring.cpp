class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 1;
        int l = 0, r = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            l = i, r = i +1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > end) {
                    start = l, end = r - l + 1;
                }
                l--;
                r++;
            }

            l = i - 1, r = i +1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > end) {
                    start = l, end = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, end);
    }
};