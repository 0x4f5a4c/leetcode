
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/?envType=daily-question&envId=2026-08-14

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0, j = 0, n = s.size();
        int res = 0;    
        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 2) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};

class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<int, int> freq; 

        int left = 0, length = 0; 

        for(int right = 0; right < s.size(); right++){

            freq[s[right]]++; 

            while(freq[s[right]] > 2){

                freq[s[left]]--; 
                left++; 
            }

            length = max(length, right - left + 1);
        }

        return length;  
    }
};
