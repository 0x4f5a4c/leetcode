// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// using hash_map
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = true;
        }
        for(int i=0; i < nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(int i=0; i < nums.size(); i++){
            if(map[nums[i]] == true){
                int j=0; int count=0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                maxlen = max(maxlen, count);
            }
        }
        return maxlen;
    }
};

// another approach using unordered_set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int x = it;
                int count = 1;

                while (st.find(x + 1) != st.end()) {
                    x += 1;
                    count += 1;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};

// better solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int last_smallest = INT_MIN;
        int curr_count = 0, longest = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 == last_smallest) {
                curr_count++;
                last_smallest = nums[i];
            } else if (nums[i] != last_smallest) {
                curr_count = 1;
                last_smallest = nums[i];
            }

            longest = max(longest, curr_count);
        }

        return longest;
    }
};


// first thought -- brute force   O(n^2)
class Solution {
public:

    bool linear_search(vector<int> &nums, int x) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) return true;
        }

        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int longest = 1, n = nums.size();
        if (n == 0 || n == 1) return n;
        for (int i = 0; i < n; ++i) {
            int count = 1;
            int x = nums[i];
            while (linear_search(nums, x+1) == true) {
                x = x + 1;
                count = count+1;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
