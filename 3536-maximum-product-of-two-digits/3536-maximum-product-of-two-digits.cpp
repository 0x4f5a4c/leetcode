class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while (n > 0) {
            int lastDigit = n % 10;
            if (lastDigit >= first) {
                second = first;
                first = lastDigit;
            } else if (lastDigit > second) {
                second = lastDigit;
            }

            n /= 10;
        }

        return first * second;
    }
};