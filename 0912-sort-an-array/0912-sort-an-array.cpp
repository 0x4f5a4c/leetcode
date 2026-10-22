// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merging(vector<int> &nums, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; ++i) L[i] = nums[l + i];
        for (int j = 0; j < n2; ++j) R[j] = nums[mid + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) nums[k] = L[i++];
            else nums[k] = R[j++];
            k++;
        }

        while (i < n1) nums[k++] = L[i++];
        while (j < n2) nums[k++] = R[j++];
    }

    void _merge(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        _merge(nums, l, mid);
        _merge(nums, mid + 1, r);
        merging(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        _merge(nums, 0, nums.size() - 1);
        return nums;
    }
};
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();