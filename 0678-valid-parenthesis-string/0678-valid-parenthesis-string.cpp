class Solution {
public:
    bool checkValidString(string s) {
        int cmax = 0, cmin = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                cmin++;
                cmax++;
            } else if (ch == ')') {
                cmin--;
                cmax--;
            } else {
                cmin--;
                cmax++;
            }

            if (cmax < 0) return false;
            cmin = std::max(0, cmin);
        }

        return cmin == 0;
    }
};