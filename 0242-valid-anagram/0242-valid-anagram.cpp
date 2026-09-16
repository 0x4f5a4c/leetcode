
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());  // takes O(nlogn) time complexity
        sort(t.begin(), t.end());  // takes O(nlogn) time complexity
        return s == t;
    }
    // total time complexity: O(nlogn)
    // space complexity: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) for the sorted strings.
};