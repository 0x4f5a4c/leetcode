class Solution {
public:
    int minSwaps(string s) {
        int ones = 0, zeros = 0;
        for (char ch : s) {
            if (ch == '1') ones++;
            else zeros++;
        }

        int n = s.size();
        if (abs(zeros - ones) > 1) return -1;

        int missing1 = 0, missing0 = 0;

        for (int i = 0; i < n; i += 2) {
            if (s[i] != '0') missing0++;
            else missing1++;
        }

        return zeros == ones ? min(missing1, missing0) : zeros > ones ? missing0 : missing1;
    }
};