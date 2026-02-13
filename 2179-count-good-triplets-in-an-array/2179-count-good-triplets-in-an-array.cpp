class Solution {
public:
    vector<long long> seg;
    int n;

    // Update position pos by +1
    void update(int i, int l, int r, int pos) {
        if (l == r) {
            seg[i] += 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2*i+1, l, mid, pos);
        else
            update(2*i+2, mid+1, r, pos);

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    // Query sum in range [ql, qr]
    long long query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr)
            return seg[i];

        int mid = (l + r) / 2;

        return query(2*i+1, l, mid, ql, qr)
             + query(2*i+2, mid+1, r, ql, qr);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();

        vector<int> pos2(n);
        for (int i = 0; i < n; i++)
            pos2[nums2[i]] = i;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = pos2[nums1[i]];

        seg.resize(4*n);

        vector<long long> left(n), right(n);

        // Step 1: count smaller on left
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0)
                left[i] = query(0, 0, n-1, 0, arr[i]-1);
            update(0, 0, n-1, arr[i]);
        }

        // reset segment tree
        fill(seg.begin(), seg.end(), 0);

        // Step 2: count greater on right
        for (int i = n-1; i >= 0; i--) {
            if (arr[i] < n-1)
                right[i] = query(0, 0, n-1, arr[i]+1, n-1);
            update(0, 0, n-1, arr[i]);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += left[i] * right[i];

        return ans;
    }
};