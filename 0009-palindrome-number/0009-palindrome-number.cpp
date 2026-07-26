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

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long reverse = 0;
        int xcopy = x;

        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return reverse == xcopy;
    }
};
