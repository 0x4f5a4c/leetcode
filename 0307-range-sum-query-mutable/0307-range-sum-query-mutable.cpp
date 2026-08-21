class NumArray {
public:
    int n;
    vector<int> segment_tree;

    void build_tree(int i, int l, int r, vector<int> &nums) {
        // base case
        if (l == r) {
            segment_tree[i] = nums[l];
            return;
        }

        // build on left and right
        int mid = l + (r - l) / 2;
        build_tree(2*i+1, l, mid, nums);
        build_tree(2*i+2, mid + 1, r, nums);

        segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2 * i + 2];
    }

    // update the segment tree -- point update
    void update_tree(int index, int val, int i, int l, int r) {
        // base case 
        if (l == r) {
            segment_tree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (index <= mid) {
            // in the left side
            update_tree(index, val, 2*i+1, l, mid);
        } else {
            update_tree(index, val, 2*i+2, mid+1, r);
        }

        segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
    }

    // now query the tree

    int sum_query(int left, int right, int i, int l, int r) {
        // out of bound condition
        if (l > right || r < left) return 0;
        if (l >= left && r <= right) {
            // in the range
            return segment_tree[i];
        } else {
            int mid = l + (r - l) / 2;
            return sum_query(left, right, 2*i+1, l, mid) + sum_query(left, right, 2*i+2, mid+1, r);
        }
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segment_tree.resize(4*n);
        build_tree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        update_tree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return sum_query(left, right, 0, 0, n-1);
    }

    // int update_range() {
    //     // use lazy propagation
    // }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */