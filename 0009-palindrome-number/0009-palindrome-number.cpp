class Solution {
public:
    bool isPalindrome(int x) {
        // basic thought
        string str = to_string(x);
        int l = 0, r = str.size() - 1;
        while (l <= r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};