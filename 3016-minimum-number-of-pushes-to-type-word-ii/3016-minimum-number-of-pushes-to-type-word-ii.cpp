class Solution {
public:
    // space complexity : O(26)
    // time complexity : O(log n) + O(26) which is almost O(logn)
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> map_freq(26, 0);
        for (char &ch : word) map_freq[ch - 'a']++;
        sort(map_freq.begin(), map_freq.end(), greater<int>());  // decending order frequency 
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int freq = map_freq[i];
            int press = (i/8) + 1;
            ans += (freq * press);
        }

        return ans;
    }
};