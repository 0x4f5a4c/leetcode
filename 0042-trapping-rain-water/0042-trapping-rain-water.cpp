
// using extra space
class Solution {
public:

    // compute left_max and right_max for each 
    void _compute_right_maximum_(vector<int> &arr, vector<int> &heights, int n) {
        arr.resize(n);
        arr[n-1] = 0;

        for (int i = n-2; i >= 0; --i) arr[i] = max(arr[i+1], heights[i+1]);
    }

    void _compute_left_maximum_(vector<int> &arr, vector<int> &heights, int n) {
        // this will modify the arr, not height
        arr.resize(n);
        arr[0] = 0;

        for (int i = 1; i < n; ++i) arr[i] = max(arr[i-1], heights[i-1]);
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;
        vector<int> left_max, right_max;
        _compute_left_maximum_(left_max, height, n);  // computing all the left max
        _compute_right_maximum_(right_max, height, n);  // computing all the right max

        // now computing the total trapped water
        int curr_trap = 0, total_trapped = 0;
        for (int i = 0; i < n; ++i) {
            curr_trap = min(left_max[i], right_max[i]) - height[i];
            if (curr_trap > 0) total_trapped += curr_trap;
        }

        return total_trapped;
    }
};