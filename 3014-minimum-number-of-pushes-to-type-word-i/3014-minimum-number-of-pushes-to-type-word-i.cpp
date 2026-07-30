class Solution {
public:
    // time complexity : O(26/8) almost O(1)
    // space complexity : O(1)
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8) return n;
        int sz = n/8;
        int rem = n % 8;
        int ans = 0;
        for (int i = 1; i <= sz; ++i) {
            ans += i * 8;
        }
        if (rem == 0) return ans;
        ans = ans + (sz + 1) * rem;
        return ans;
    }
};

class Solution {
public:
    // another way of solving using frequency count
    int minimumPushes(string word) {
        int n = word.size();
        // this frequency also take space 
        // O(26)
        vector<int> freq_map(26, 0);
        for (auto &ch : word) freq_map[ch - 'a']++;
        // sorting will take time off course  -- O(logn)
        sort(freq_map.begin(), freq_map.end(), greater<int>());  // sort the frequency in decending order 
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int freq = freq_map[i];
            int press = (i/8) + 1;
            ans += (freq * press);
        }

        return ans;
    }
};
