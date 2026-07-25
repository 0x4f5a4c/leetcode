class Solution {
public:
    // guess to brute force 
    // time complexity : O(n) + O(n)
    // space complexity : O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;  // [element, count]
        int n = nums.size();
        // O(n)
        for (int i = 0; i < n; ++i) {
            mpp[nums[i]]++;    
        }

        int ans;
        // O(n)
        for (auto data : mpp) {
            if (data.second > n/2) {
                ans = data.first;
                break;
            }
        }

        return ans;
    }
};

class Solution {
public:
    // approach 2
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting takes some time sweetheart
        int n = nums.size();
        return nums[n/2];
    }
};

class Solution {
public:
    // time complexity : O(n)
    // space complexity : O(1)
    
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int n : nums) {
            if (count == 0) candidate = n;
            if (n == candidate) count++;
            else count--;
        }

        return candidate;
     }
};
