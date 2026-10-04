class Solution {
public:
    int minRotations(string s) {
        int current = '0';
        int total_rotation = 0;

        for (char target : s) {
            int curr_val = current - '0';
            int target_val = target - '0';

            int diff = std::abs(curr_val - target_val);
            total_rotation += std::min(diff, 10 - diff);
            current = target;
        }

        return total_rotation;
    }
};