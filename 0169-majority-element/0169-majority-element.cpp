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