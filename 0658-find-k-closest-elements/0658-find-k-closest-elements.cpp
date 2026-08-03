class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int n : arr) {
            if (k > 0) {
                min_heap.push(n);
                k--;
            } else if (abs(min_heap.top() - x) > abs(n - x)) {
                min_heap.pop();
                min_heap.push(n);
            }
        }

        vector<int> ans;
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }

        return ans;
    }
};

class Solution {
public:
    // better then before 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        while (r - l + 1 > k) {
            if (abs(arr[l] - x) > abs(arr[r] - x)) l++;
            else r--;
        }

        vector<int> ans;
        for (int i = l; i <= r; ++i) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
