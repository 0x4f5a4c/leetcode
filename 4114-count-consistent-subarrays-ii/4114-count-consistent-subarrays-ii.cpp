class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_min(n, -1), right_min(n, n);

        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            left_min[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right_min[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> left_valid(n, -1), right_valid(n, n);
        vector<int> last_zero(31, -1); 

        for (int i = 0; i < n; ++i) {
            for (int b = 0; b < 31; ++b) {
                if ((nums[i] >> b) & 1) left_valid[i] = max(left_valid[i], last_zero[b]);
                else last_zero[b] = i;
            }
        }

        fill(last_zero.begin(), last_zero.end(), n);

        for (int i = n-1; i >= 0; --i) {
            for (int b = 0; b < 31; b++) {
                if ((nums[i] >> b) & 1) right_valid[i] = min(right_valid[i], last_zero[b]);
                else last_zero[b] = i;
            }
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left  = max(left_min[i], left_valid[i]);
            long long right = min(right_min[i], right_valid[i]);

            total += (i - left) * (right - i);
        }

        return total;
    }
};