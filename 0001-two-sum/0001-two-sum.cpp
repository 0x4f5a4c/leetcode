// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// brute force approach
class Solution {
public:
    /**
     * @time complexity: O(n^2)
     * @space complexity: O(1)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/**
 * another better approach is to use a hash map to store the indices of the elements we have seen so far. This way, we can check if the complement of the current element (i.e., target - nums[i]) exists in the hash map. If it does, we have found our solution.
 * This approach has a time complexity of O(n) and a space complexity of O(n).
 */

 /**
  * @time complexity: O(n)
  * @space complexity: O(n)
  */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> numToIndex; // map to store the number and its index
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {};
    }
};

/**
 * is there any better approach than this?
 * The current approach using a hash map is already optimal with a time complexity of O(n) and a space complexity of O(n). There is no known approach that can solve the two-sum problem in less than O(n) time complexity, as we need to examine each element at least once. Therefore, the hash map approach is considered the best solution for this problem in terms of time complexity .
 * 
 * And if we try to solve this using a sorting approach, we will lose the original indices of the elements, which is required in the output. Hence, the hash map approach is the most efficient and suitable solution for this problem.
 */
