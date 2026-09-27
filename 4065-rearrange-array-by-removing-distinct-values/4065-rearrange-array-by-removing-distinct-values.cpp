class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int, int> freq;
        for (int x : nums)freq[x]++;
        int rem = nums.size();
        while (rem > 0) {
            for (auto &[val, count] : freq) {
                if (count > 0) {
                    ans.push_back(val);
                    count--;
                    rem--;
                }
            }
        }

        return ans;        
    }
};