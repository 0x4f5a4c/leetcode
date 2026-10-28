// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
// Question Link : https://neetcode.io/problems/k-th-smallest-in-lexicographical-order/question

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(long curr, long next, int limit) {
        int _count = 0;
        while (curr <= limit) {
            _count += next - curr;
            curr *= 10;
            next *= 10;
            next = min(next, (long)limit + 1);
        }

        return (int)_count;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;  // because we already count the root node or say first number

        while (k > 0) {
            int _count = count(curr, curr+1, n);
            if (_count <= k) {
                curr += 1;
                k -= _count;  // skipping the element under current subtree and moving to next subtree
            } else {
                // in the same tree, so for the next level just multiply with 10
                curr *= 10;
                k -= 1;  // because we already count the current number
            }
        }

        return (int)curr;
    }
};