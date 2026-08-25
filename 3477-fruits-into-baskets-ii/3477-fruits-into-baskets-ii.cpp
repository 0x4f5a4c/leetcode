// Optimal Solution -- Segment Tree 

class Solution {
    vector<int> segment_tree;
public:
    void build_tree(int curr_idx, int left, int right, vector<int> &baskets) {
        if (left == right) {
            segment_tree[curr_idx] = baskets[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build_tree(2 * curr_idx + 1, left, mid, baskets);
        build_tree(2 * curr_idx + 2, mid + 1, right, baskets);

        // store te maximum element 
        segment_tree[curr_idx] = max(segment_tree[2 * curr_idx + 1], segment_tree[2 * curr_idx + 2]);
    }

    bool query_range(int curr_idx, int left, int right, vector<int> &fruits, int fruit_val) {
        if (segment_tree[curr_idx] < fruit_val) return false;
        // base case
        if (left == right) {
            segment_tree[curr_idx] = -1;  // places
            return true;
        }

        // now go in the left or right
        int mid = left + (right - left) / 2;
        bool placed = false;
        if(segment_tree[2 * curr_idx + 1] >= fruit_val) {  // we can only move to the left part when it is possible
            placed = query_range(2 * curr_idx + 1, left, mid, fruits, fruit_val);
        } else {  // means not possible to move left so go right
            placed = query_range(2 * curr_idx + 2, mid + 1, right, fruits, fruit_val);
        }

        // also update the tree
        segment_tree[curr_idx] = max(segment_tree[2 * curr_idx + 1], segment_tree[2 * curr_idx + 2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segment_tree.resize(4*n);

        build_tree(0, 0, n-1, baskets);  // now we build the segment tree on baskets
        int unplaced = 0;
        // now for each fruite query the tree and update the tree
        for (auto &fruit : fruits) {
            if (!query_range(0, 0, n-1, fruits, fruit)) unplaced++;
        }

        return unplaced;
    }
};