// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
// Question Link : https://neetcode.io/problems/find-the-punishment-number-of-an-integer/question

#include <bits/stdc++.h>
using namespace std;
/**
 * more optimize with O(1) time complexity for per query
 * and O(n) for extra memo cache storing
 */

class Solution {
private:
    static vector<int> memo;

    static bool check(int square, int curr_sum, int num) {
        if (square == 0) return curr_sum == num;
        if (curr_sum > num) return false;

        int d = 10;
        while (square >= d / 10) {
            if (check(square / d, (square % d) + curr_sum, num)) return true;
            if (d > square) break;
            d *= 10;
        }
        return false;
    }

    static void precompute() {
        if (!memo.empty()) return;
        memo.resize(1001, 0);
        int running_sum = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (check(i * i, 0, i)) {
                running_sum += (i * i);
            }
            memo[i] = running_sum;
        }
    }

public:
    int punishmentNumber(int n) {
        precompute();
        return memo[n];
    }
};

vector<int> Solution::memo;