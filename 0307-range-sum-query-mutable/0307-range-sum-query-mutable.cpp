class NumArray {
public:
    vector<int> tree;
    int n;

    // Build segment tree
    void build(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            tree[i] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(nums, 2*i + 1, l, mid);
        build(nums, 2*i + 2, mid + 1, r);

        tree[i] = tree[2*i + 1] + tree[2*i + 2];
    }

    // Update value at index
    void updateTree(int i, int l, int r, int index, int val) {
        if (l == r) {
            tree[i] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            updateTree(2*i + 1, l, mid, index, val);
        else
            updateTree(2*i + 2, mid + 1, r, index, val);

        tree[i] = tree[2*i + 1] + tree[2*i + 2];
    }

    // Query range sum
    int query(int i, int l, int r, int ql, int qr) {
        // Completely inside
        if (ql <= l && r <= qr)
            return tree[i];

        // Completely outside
        if (r < ql || l > qr)
            return 0;

        int mid = (l + r) / 2;

        return query(2*i + 1, l, mid, ql, qr)
             + query(2*i + 2, mid + 1, r, ql, qr);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;

        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */