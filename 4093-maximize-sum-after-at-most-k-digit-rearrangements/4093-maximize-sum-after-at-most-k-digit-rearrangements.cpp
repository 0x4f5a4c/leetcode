#define ll long long

class Solution {
public:
    ll get_max_rearranged(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end(), greater<char>());
        return stoll(s);
    }
    
    long long maximizeSum(vector<int>& nums, int k) {
        ll total_sum = 0;
        vector<ll> gains;

        for(int n : nums) {
            total_sum += n;
            ll max_val = get_max_rearranged(n);
            ll gain = max_val - n;
            if (gain > 0) gains.push_back(gain);
        }
        sort(gains.begin(), gains.end(), greater<ll>());
        int ops = min((int)gains.size(), k);
        for (int i = 0; i < ops; ++i) total_sum += gains[i];

        return total_sum;
    }
};